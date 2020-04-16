/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** file for init struct
*/

#include <string.h>
#include <stdio.h>

#include "myftp.h"
#include "ftpstruct.h"

void init_serveur(server_t *serv_ftp, unsigned short port, char const *pathfile)
{
    int opt = 1;

    serv_ftp->dir = pathfile;
    serv_ftp->port = port;
    serv_ftp->tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_ftp->tcp_socket < 0)
        error_n_quit("Error: Socket creation failed.\n");
    serv_ftp->sin.sin_family = AF_INET;
    serv_ftp->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_ftp->sin.sin_port = htons(port);
    setsockopt(serv_ftp->tcp_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(serv_ftp->tcp_socket, (struct sockaddr *)&(serv_ftp->sin), sizeof(serv_ftp->sin)) == -1)
        error_n_quit("Error: Bind failed.\n");
    if (listen(serv_ftp->tcp_socket, MAX_CONNECTION_SERVER) < 0)
        error_n_quit("Error: listen connection of socket failed.\n");
}