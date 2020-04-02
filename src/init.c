/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** file for init struct
*/

#include <stdio.h>
#include "myftp.h"
#include "ftpstruct.h"

init_serveur(server_t *serv_ftp, unsigned short port, char *pathfile)
{
    int size_sin = 0;

    serv_ftp->home = pathfile;
    serv_ftp->port = port;
    serv_ftp->tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_ftp->tcp_socket == -1)
        error("Error: Socket creation failed.\n");
    serv_ftp->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_ftp->sin.sin_port = htons(port);
    serv_ftp->sin.sin_family = AF_INET;
    size_sin = sizeof(serv_ftp->sin);
    if (bind(serv_ftp->tcp_socket, &serv_ftp->sin, size_sin) == -1)
        error("Error: Bind failed.\n");
    if (listen(SOCK_STREAM, 5) == -1)
        error("Error: listen connections of socket failed.\n");
}