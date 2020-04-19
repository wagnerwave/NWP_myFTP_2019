/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** file for init struct
*/

#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include "myftp.h"
#include "ftpstruct.h"

void default_client_initialisation(client_t *client)
{
    client->fd = -1;
    client->group_fd = 0;
    client->pass_ok = false;
    client->user_ok = false;
    client->user.password = NULL;
    client->user.username = NULL;
    client->path = NULL;
}

void init_client(client_t *client, int sock, fd_set *acv_grpfd, server_t *srv)
{
    client->fd = sock;
    client->group_fd = acv_grpfd;
    client->path = strdup(srv->path);
}

void init_serveur(server_t *srv, unsigned short port, char *pathfile)
{
    int opt = 1;
    struct stat s_stat;

    stat(pathfile, &s_stat);
    if (!S_ISDIR(s_stat.st_mode))
        error_n_quit("Error: Pathfile incorrect.\n");
    srv->path = pathfile;
    srv->port = port;
    srv->tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (srv->tcp_socket < 0)
        error_n_quit("Error: Socket creation failed.\n");
    srv->sin.sin_family = AF_INET;
    srv->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    srv->sin.sin_port = htons(port);
    setsockopt(srv->tcp_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(srv->tcp_socket, (struct sockaddr *)&(srv->sin),
        sizeof(srv->sin)) < 0)
        error_n_quit("Error: Bind failed.\n");
    if (listen(srv->tcp_socket, MAX_CONNECTION_SERVER) < 0)
        error_n_quit("Error: listen connection of socket failed.\n");
}