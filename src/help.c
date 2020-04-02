/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Help for FTP
*/

#include <stdio.h>
#include <stdlib.h>

void display_help(char *binary_name)
{
    printf("USAGE: %s port path\n", binary_name);
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the anonymous user\n");
}