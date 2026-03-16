#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

#define MAXLINE 1024

int main(int argc, char **argv)
{
    struct addrinfo *p, *listp;
    struct addrinfo hint;
    int rc, flags;
    char buf[MAXLINE];

    /* Get a list of addrinfo records */
    memset(&hint, 0, sizeof(struct addrinfo));  // hint 구조체 초기화
    hint.ai_family = AF_INET;
    hint.ai_socktype = SOCK_STREAM;
    
    if (rc = getaddrinfo(argv[1], NULL, &hint, &listp) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(0);
    }

    /* Display each IP address */
    flags = NI_NUMERICHOST;
    for (p = listp; p; p = (*p).ai_next)
    {
        getnameinfo((*p).ai_addr, (*p).ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        printf("%s\n", buf);
    }

    freeaddrinfo(listp);

    exit(0);
}