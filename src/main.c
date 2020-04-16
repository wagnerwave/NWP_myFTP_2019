/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Main for my_ftp project
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "myftp.h"
#include "ftpstruct.h"

int main(int ac, char **av)
{
    server_t *serv_ftp = malloc(sizeof(server_t));

    if (serv_ftp == NULL)
        return 84;
    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        display_help(av[0]);
        return 0;
    } else if (ac < 3) {
        return 84;
    } else {
        init_serveur(serv_ftp, (unsigned short)atoi(av[1]), av[2]);
        file_transfer_protocol(serv_ftp);
    }
    return 0;
}