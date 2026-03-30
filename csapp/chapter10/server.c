#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "open_listenfd.h"

#define MAX_LINE 256

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    char *port = argv[1];
    char echo_buffer[MAX_LINE];
    int connfd;
    int recv_b;
    struct sockaddr_storage serv_addr;
    socklen_t serv_addr_size = sizeof(struct sockaddr_storage);
    char host_name[MAX_LINE];
    char service_name[MAX_LINE];

    int listenfd = open_listenfd(port);     // create listen fd
    if (listenfd < 0)
    {
        fprintf(stderr, "open_listen error\n");
        exit(1);
    }

    while (1)
    {
        if ((connfd = accept(listenfd, (struct sockaddr *)(&serv_addr), &serv_addr_size)) == -1)  
        {
            fprintf(stderr, "accept() error: %s\n", strerror(errno));
            continue;
        }

        getnameinfo((struct sockaddr*)(&serv_addr), serv_addr_size,     
                    host_name, MAX_LINE,
                    service_name, MAX_LINE, 0);

        printf("Connected to (%s, %s)\n", host_name, service_name);
        fflush(stdout);

        // echo
        while ((recv_b = recv(connfd, echo_buffer, MAX_LINE, 0)) > 0)                    
        {            
            printf("server recieved %d bytes\n", recv_b);
            send(connfd, echo_buffer, recv_b, 0);
        }

        if (recv_b == 0)
            printf("Connection elegantly closed: [EOF]\n");
        else if (recv_b == -1)
            fprintf(stderr, "recv() error: %s\n", strerror(errno));

        close(connfd);
    }
}