#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "open_clientfd.h"

#define MAX_LINE 256

int main(int argc, char **argv)
{
    char *hostname = argv[1];
    char *port = argv[2];
    char send_buffer[MAX_LINE];
    char recv_buffer[MAX_LINE];
    int clientfd;
    ssize_t send_b, recv_b;

    clientfd = open_clientfd(hostname, port);


    while(fgets(send_buffer, MAX_LINE, stdin) != NULL)
    {
        send_b = send(clientfd, send_buffer, MAX_LINE, 0);
            if (send_b == -1)
            {
                fprintf(stderr, "send() error: %s\n", strerror(errno));
                break;
            }
        recv_b = recv(clientfd, recv_buffer, MAX_LINE, 0);
            if (recv_b == -1)
            {
                fprintf(stderr, "recv() error: %s\n", strerror(errno));
                break;
            }
        recv_buffer[recv_b] = '\0';
        printf("echo: %s", recv_buffer);
        fflush(stdout);
    }

    close(clientfd);
    return 0;
}