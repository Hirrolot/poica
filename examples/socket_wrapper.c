#include "../include/sum_type.h"

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

SocketRes socket_wrapper(int domain, int type, int protocol) {
    int fd = socket(domain, type, protocol);

    if (fd == -1) {
        switch (errno) {
        case EACCES:
            return MkErr(MkEACCES());
        case EAFNOSUPPORT:
            return MkErr(MkEAFNOSUPPORT());
        case EINVAL:
            return MkErr(MkEINVAL());
        case EMFILE:
            return MkErr(MkEMFILE());
        case ENOBUFS:
            return MkErr(MkENOBUFS());
        case ENOMEM:
            return MkErr(MkENOMEM());
        case EPROTONOSUPPORT:
            return MkErr(MkEPROTONOSUPPORT());
        default:
            return MkErr(MkOtherErr(errno));
        }
    } else {
        return MkOk(fd);
    }
}

int main(void) {
    SocketRes res = socket_wrapper(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    MATCH(&res) {
        CASE(MkOk, fd) {
            printf("fd = %d\n", *fd);
            close(*fd);
        }
        CASE(MkErr, error) {
            puts("An error has occurred!");
            // Handle `error` here...
        }
    }
}
