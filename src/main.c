/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Main for my_ftp project
*/

#include "myftp.h"
#include "ftpstruct.h"


int main(int ac, char **av)
{


    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        display_help(av[0]);
    else if (ac < 3) {
        init();
    }
    return 0;
}