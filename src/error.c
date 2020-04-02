/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** All function for error
*/

#include <stdio.h>
#include <unistd.h>

void error(char *msg)
{
    fprintf(stderr, msg);
    exit(84);
}