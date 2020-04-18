/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Function containt  the most easiest cmd
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ftpstruct.h"
#include "myftp.h"

void noop(client_t *client, char **input, size_t nb)
{
    char *ok = "200 NOOP ok.\r\n";
    char *err = "530 Please login with USER and PASS.\r\n";

    (void)input;
    (void)nb;
    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    write(client->fd, ok, strlen(ok));
}

void help(client_t *client, char **input, size_t nb)
{
    char *code = "214-The following commands are recognized.\r\n";
    char *end = "214 Help OK.\r\n";
    char *err = "530 Please login with USER and PASS.\r\n";

    (void)input;
    (void)nb;
    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    write(client->fd, code, strlen(code));
    for (size_t i = 0; commands[i].cmd != NULL; i++) {
        write(client->fd, commands[i].cmd, strlen(commands[i].cmd));
        write(client->fd, "  ", 2);
    }
    write(client->fd, "\n", 1);
    write(client->fd, end, strlen(end));
}