/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Interpret user input and use for function
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ftpstruct.h"
#include "myftp.h"

static char *check_command(char *input)
{
    printf("check cmd");
    for (size_t i = 0; commands[i].cmd != NULL; i++) {
        if (strcmp(commands[i].cmd, input) == 0)
            (command[i].func)()
    }
    return NULL;
}

void interpert_client_input(int socket, char *buffer, user_t *user)
{
    char **content = strtowordarray(buffer, SPACE);
    char *cmd = cmd = check_command(content[0]);

    if (cmd == NULL) {
        unknown_command(socket);
        return;
    }

}