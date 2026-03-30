#ifndef OPEN_CLIENTFD_H
#define OPEN_CLIENTFD_H

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int open_clientfd(char *hostname, char *port)
{
    int clientfd;
    struct addrinfo *p, *listp, hints;
    int errcode;

    memset(&hints, 0, sizeof(struct addrinfo));     // initialize hints to 0 or NULL
    hints.ai_socktype = SOCK_STREAM;                // TCP
    hints.ai_flags = AI_NUMERICSERV;                // port number only
    hints.ai_flags = AI_ADDRCONFIG;                 // use configured family (IPv4, IPv6)

    if ((errcode = getaddrinfo(hostname, port, &hints, &listp)) != 0)                       // get addrinfo structs list
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(errcode));                  // if getaddrinfo fail, get error. return -1
        return -1;
    }

    for (p = listp; p; p = (*p).ai_next)                                                    // go through all addrinfo structs
    {
        if ((clientfd = socket((*p).ai_family, (*p).ai_socktype, (*p).ai_protocol)) < 0)    // make socket. if fail, go to next addrinfo struct
            continue;
        
        if (connect(clientfd, (*p).ai_addr, (*p).ai_addrlen) != -1)                         // make connection. if fail, close fd and go to next addrinfo struct
            break;  // connection success
        close(clientfd);
    }

    freeaddrinfo(listp);   // clean up
    if (!p)                 // if all addrinfo structs fail, return -1
        return -1;
    else                    // if success, return clientfd
        return clientfd;
}


#endif