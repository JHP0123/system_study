#ifndef OPEN_LISTENFD_H
#define OPEN_LISTENFD_H

#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

#define LISTENQUE 1024

int open_listenfd(char *port)
{
    int listenfd, errcode;
    struct addrinfo *listp, *p, hints;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV | AI_ADDRCONFIG;

    if ((errcode = getaddrinfo(NULL, port, &hints, &listp)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(errcode));
        return -1;
    }

    for (p = listp; p; p = (*p).ai_next)
    {
        if (listenfd = socket((*p).ai_family, (*p).ai_socktype, (*p).ai_protocol) == -1)
            continue; 

        if (bind(listenfd, (*p).ai_addr, (*p).ai_addrlen) == 0)
            break;
        close(listenfd);
    }

    freeaddrinfo(listp);
    if (!p)
        return -1;

    if (listen(listenfd, LISTENQUE) == -1)
    {
        close(listenfd);
        return -1;
    }
    else
        return listenfd;
}

#endif