#include "../src/sum_type.h"
#include "../src/unit_type.h"

#include <errno.h>
#include <stdio.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// clang-format off
SUM(
    SocketErr,
    VARIANT(MkEACCES OF UnitType)
    VARIANT(MkEAFNOSUPPORT OF UnitType)
    VARIANT(MkEINVAL OF UnitType)
    VARIANT(MkEMFILE OF UnitType)
    VARIANT(MkENOBUFS OF UnitType)
    VARIANT(MkENOMEM OF UnitType)
    VARIANT(MkEPROTONOSUPPORT OF UnitType)
    VARIANT(MkOtherErr OF int)
);

SUM(
    SocketRes,
    VARIANT(MkOk OF int)
    VARIANT(MkErr OF SocketErr)
);
// clang-format on

#define CHECK(error_name, var_name)                                            \
    CASE(Mk##error_name, var_name) {                                           \
        puts(#error_name);                                                     \
    }

void print_socket_err(const SocketErr *err) {
    MATCH(err) {
        CHECK(EACCES, _e1)
        CHECK(EAFNOSUPPORT, _e2)
        CHECK(EINVAL, _e3)
        CHECK(EMFILE, _e4)
        CHECK(ENOBUFS, _e5)
        CHECK(ENOMEM, _e6)
        CHECK(EPROTONOSUPPORT, _e7)
        CASE(MkOtherErr, err_number) {
            printf("Other: %d\n", *err_number);
        }
    }
}

#undef CHECK

#define CHECK(error_name)                                                      \
    case error_name:                                                           \
        return MkErr(Mk##error_name(unit_type()));

SocketRes socket_wrapper(int domain, int type, int protocol) {
    int fd;

    if ((fd = socket(domain, type, protocol)) == -1) {
        switch (errno) {
            CHECK(EACCES)
            CHECK(EAFNOSUPPORT)
            CHECK(EINVAL)
            CHECK(EMFILE)
            CHECK(ENOBUFS)
            CHECK(ENOMEM)
            CHECK(EPROTONOSUPPORT)
        default:
            return MkErr(MkOtherErr(errno));
        }
    } else {
        return MkOk(fd);
    }
}

#undef CHECK

int main(void) {
    SocketRes res = socket_wrapper(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    MATCH(&res) {
        CASE(MkOk, fd) {
            printf("fd = %d\n", *fd);
            close(*fd);
        }
        CASE(MkErr, error) {
            print_socket_err((const SocketErr *)error);
        }
    }
}
