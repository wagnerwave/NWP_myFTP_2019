/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Main function for FTP serveur
*/

#include <unistd.h>
#include <sys/socket.h>
#include "ftpstruct.h"
#include "myftp.h"

static status_socket_t get_status_code(server_t *serv_ftp)
{
   /* char buffer[2048] = { 0 };
    int toto = read(serv_ftp->new_tcp_socket, buffer, 2048); */
    return (SOCKET_NONE_INIT);
}

void running_serveur(server_t *serv_ftp)
{
    status_socket_t status_code = SOCKET_NONE_INIT;
    pid_t child;

    while (1) {
        status_code = get_status_code(serv_ftp);
        /* if (status_code != SOCKET_DONE) {
            error_msg("Error: accept connection failed.\n");
            continue;
        }
        child = fork();
        if (child == -1) {
            error_msg("Error: fork failed.\n");
            continue;
        }
        if (child == 0)
            client_serveur(serv_ftp->sin);
        else
            return;
        */
    }
}

void close_serveur(server_t *serv_ftp)
{
    close(serv_ftp->tcp_socket);
}