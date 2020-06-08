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
// clang-format on

void print_socket_err(const SocketErr *err) {
    MATCH(err) {
        CASE(MkEACCES, _e1) {
            puts("MkEACCESS");
        }
        CASE(MkEAFNOSUPPORT, _e2) {
            puts("MkEAFNOSUPPORT");
        }
        CASE(MkEINVAL, _e3) {
            puts("MkEINVAL");
        }
        CASE(MkEMFILE, _e4) {
            puts("MkEMFILE");
        }
        CASE(MkENOBUFS, _e5) {
            puts("MkENOBUFS");
        }
        CASE(MkENOMEM, _e6) {
            puts("MkENOMEM");
        }
        CASE(MkEPROTONOSUPPORT, _e7) {
            puts("MkEPROTONOSUPPORT");
        }
        CASE(MkOtherErr, err_number) {
            printf("Other: %d\n", *err_number);
        }
    }
}

// clang-format off
SUM(
    SocketRes,
    VARIANT(MkOk OF int)
    VARIANT(MkErr OF SocketErr)
);
// clang-format on

#define CHECK(error_name)                                                      \
    case error_name:                                                           \
        return MkErr(Mk##error_name(unit_type()))

SocketRes socket_wrapper(int domain, int type, int protocol) {
    int fd;

    if ((fd = socket(domain, type, protocol)) == -1) {
        switch (errno) {
            CHECK(EACCES);
            CHECK(EAFNOSUPPORT);
            CHECK(EINVAL);
            CHECK(EMFILE);
            CHECK(ENOBUFS);
            CHECK(ENOMEM);
            CHECK(EPROTONOSUPPORT);
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
