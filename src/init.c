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
}

void init_client(client_t *client, int sock, fd_set *activ_group_fd)
{
    client->fd = sock;
    client->group_fd = activ_group_fd;
}

void init_serveur(server_t *serv_ftp, unsigned short port, char const *pathfile)
{
    int opt = 1;
    struct stat s_stat;

    stat(pathfile, &s_stat);
    if (!S_ISDIR(s_stat.st_mode))
        error_n_quit("Error: Pathfile incorrect.\n");
    serv_ftp->dir = pathfile;
    serv_ftp->port = port;
    serv_ftp->tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_ftp->tcp_socket < 0)
        error_n_quit("Error: Socket creation failed.\n");
    serv_ftp->sin.sin_family = AF_INET;
    serv_ftp->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_ftp->sin.sin_port = htons(port);
    setsockopt(serv_ftp->tcp_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(serv_ftp->tcp_socket, (struct sockaddr *)&(serv_ftp->sin),
        sizeof(serv_ftp->sin)) < 0)
        error_n_quit("Error: Bind failed.\n");
    if (listen(serv_ftp->tcp_socket, MAX_CONNECTION_SERVER) < 0)
        error_n_quit("Error: listen connection of socket failed.\n");
}