#include "../src/sum_type.h"

#include <errno.h>
#include <stdio.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// clang-format off
SUM(
    SocketErr,
    VARIANT(MkEACCES)
    VARIANT(MkEAFNOSUPPORT)
    VARIANT(MkEINVAL)
    VARIANT(MkEMFILE)
    VARIANT(MkENOBUFS)
    VARIANT(MkENOMEM)
    VARIANT(MkEPROTONOSUPPORT)
    VARIANT(MkOtherErr OF int)
);

SUM(
    SocketRes,
    VARIANT(MkOk OF int)
    VARIANT(MkErr OF SocketErr)
);
// clang-format on

#define CHECK(error_name)                                                      \
    CASE(Mk##error_name) {                                                     \
        puts(#error_name);                                                     \
    }

void print_socket_err(const SocketErr *err) {
    MATCH(err) {
        CHECK(EACCES)
        CHECK(EAFNOSUPPORT)
        CHECK(EINVAL)
        CHECK(EMFILE)
        CHECK(ENOBUFS)
        CHECK(ENOMEM)
        CHECK(EPROTONOSUPPORT)
        CASE(MkOtherErr, err_number) {
            printf("Other: %d\n", *err_number);
        }
    }
}

#undef CHECK

#define CHECK(error_name)                                                      \
    case error_name:                                                           \
        return MkErr(Mk##error_name());

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
