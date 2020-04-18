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

static void client_management(client_t *client)
{
    char *input = NULL;

    input = get_next_line(client->fd);
    if (input == NULL) {
        close(client->fd);
        FD_CLR(client->fd, client->group_fd);
        return;
    }
    interpert_client_input(client, input);
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

static void in_the_socket(server_t *serv_ftp, client_t *client)
{
    if (client->fd == serv_ftp->tcp_socket) {
        connection_client(serv_ftp->tcp_socket, client->group_fd);
    } else {
        client_management(client);
    }
}

void file_transfer_protocol(server_t *serv_ftp)
{
    fd_set activ_group_fd;
    fd_set read_group_fd;
    client_t **client = malloc(sizeof(client_t *) * (FD_SETSIZE + 1));

    if (client == NULL)
        error_n_quit("Error: malloc client fd failed.\n");
    for (int x = 0; x < FD_SETSIZE; x++) {
        client[x] = calloc(1, sizeof(client_t));
        if (client[x] == NULL)
            error_n_quit("Error: malloc client fd failed.\n");
        default_client_initialisation(client[x]);
    }
    FD_ZERO(&activ_group_fd);
    FD_SET(serv_ftp->tcp_socket, &activ_group_fd);
    while (1) {
        read_group_fd = activ_group_fd;
        if (select(FD_SETSIZE, &read_group_fd, NULL, NULL, NULL) < 0)
            error_n_quit("Error: Select failed.\n");
        for (int sock = 0; sock < FD_SETSIZE; sock++) {
            init_client(client[sock], sock, &activ_group_fd, serv_ftp);
            if (FD_ISSET(sock, &read_group_fd)) {
                in_the_socket(serv_ftp, client[sock]);
            }
        }
    }
}