/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Main function for FTP serveur
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ftpstruct.h"
#include "myftp.h"

static void client_management(int fd, fd_set *activ_group_fd)
{
    user_t user = {NULL, NULL};
    char *input = NULL;

    while (1) {
        input = get_next_line(fd);
        if (input == NULL)
            break;
        interpert_client_input(fd, input, &user);
    }
    close(fd);
    FD_CLR(fd, activ_group_fd);
}

static void connection_client(int sock, fd_set *activ_group_fd)
{
    char *msg_connexion = "220 Connection Establishment\n";
    int new_tcp_socket = 0;
    struct sockaddr_in client;
    socklen_t addr_size = sizeof(client);

    new_tcp_socket = accept(sock, (struct sockaddr *)&client, &addr_size);
    if (new_tcp_socket < 0)
        error_n_quit("Error: Accept the serveur socket failed.\n");
    write(new_tcp_socket, msg_connexion, strlen(msg_connexion));
    FD_SET(new_tcp_socket, activ_group_fd);
}

static void in_the_socket(int fd, server_t *serv_ftp, fd_set *activ_group_fd)
{
    if (fd == serv_ftp->tcp_socket) {
        connection_client(serv_ftp->tcp_socket, activ_group_fd);
    } else {
        client_management(fd, activ_group_fd);
    }
}

void file_transfer_protocol(server_t *serv_ftp)
{
    fd_set activ_group_fd;
    fd_set read_group_fd;

    FD_ZERO(&activ_group_fd);
    FD_SET(serv_ftp->tcp_socket, &activ_group_fd);
    while (1) {
        read_group_fd = activ_group_fd;
        if (select(FD_SETSIZE, &read_group_fd, NULL, NULL, NULL) < 0)
            error_n_quit("Error: Select failed.\n");
        for (size_t i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_group_fd)) {
                in_the_socket(i, serv_ftp, &activ_group_fd);
            }
        }
    }
}