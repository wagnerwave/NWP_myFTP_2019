/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Interpret user input and use for function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ftpstruct.h"
#include "myftp.h"

void interpert_client_input(client_t *client, char *input)
{
    char **content = strtowordarray(input, SPACE);
    size_t nb_space = 0;
    size_t i = 0;

    while (content[nb_space])
        nb_space++;
    for (i = 0; commands[i].cmd != NULL; i++)
        if (strcmp(commands[i].cmd, content[0]) == 0)
            break;
    if (commands[i].cmd != NULL)
        (commands[i].func)(client, content, nb_space);
    else
        unknown_command(client->fd);
    for (size_t a = 0; content[a]; a++)
        free(content[a]);
    free(content);
}