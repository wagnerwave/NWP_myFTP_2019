/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** All function for error
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void error_msg(char *msg)
{
    fprintf(stderr, "%s", msg);
}

void error_n_quit(char *msg)
{
    error_msg(msg);
    exit(84);
}