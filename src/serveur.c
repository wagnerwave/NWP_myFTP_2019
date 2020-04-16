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

static int get_client_data(int socket)
{
    char buffer[1024];
    int nbytes = read(socket, buffer, 1024);

    if (nbytes < 0)
      error_n_quit("Error: Read fail.\n");
    else if (nbytes == 0)
        return -1;
    else
        interpert_client_input(socket, buffer);
    return 0;
}

static void client_management(int fd, fd_set *activ_group_fd)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        error_n_quit("Error: Malloc for user failed.\n");
    while (1) {
        get_client_data(fd);
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

    printf("New user enter in to the server\n"); // A enlever
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