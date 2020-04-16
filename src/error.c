/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** All function for error
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void unknown_command(int socket)
{
    char *error_msg = "500 Syntax error or command unrecognized\n";

    write(socket, error_msg, strlen(error_msg));
}

void error_msg(char *msg)
{
    fprintf(stderr, "%s", msg);
}

void error_n_quit(char *msg)
{
    error_msg(msg);
    exit(84);
}