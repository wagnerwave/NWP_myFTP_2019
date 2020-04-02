/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** All function for error
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void error(char *msg)
{
    fprintf(stderr, "%s", msg);
    exit(84);
}