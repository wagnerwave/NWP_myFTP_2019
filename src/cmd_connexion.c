/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Function for FTP command
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ftpstruct.h"
#include "myftp.h"

void user_connexion(client_t *client, char **input, size_t nb)
{
    char *err_msg = "530 Can't change from guest user.\r\n";
    char *perm_err = "530 Permission denied.\r\n";
    char *ok = "331 Please specify the password.\r\n";

    if (client->user_ok == true && client->pass_ok == true)  {
        write(client->fd, err_msg, strlen(err_msg));
        return;
    }
    if (nb == 1) {
        write(client->fd, perm_err, strlen(perm_err));
        return;
    }
    client->user.username = strdup(input[1]);
    write(client->fd, ok, strlen(ok));
    client->user_ok = true;
}

void pass_connexion(client_t *client, char **input, size_t nb)
{
    char *already_con = "230 Already logged in.\r\n";
    char *ok = "230 Login successful.\r\n";
    char *err = "530 Login incorrect.\r\n";
    char *user_first = "503 Login with USER first.\r\n";

    if (client->user_ok == false ) {
        write(client->fd, user_first, strlen(user_first));
        return;
    }
    if (client->user_ok == true && client->pass_ok == true) {
        write(client->fd, already_con, strlen(already_con));
        return;
    }
    client->user.password = "";
    if (strcmp(client->user.username, "Anonymous\r") == 0) {
        write(client->fd, ok, strlen(ok));
        client->pass_ok = true;
    } else {
        write(client->fd, err, strlen(err));
        client->user.username ? free(client->user.username) : 0;
        client->user.username = NULL;
    }
}

void quit_connexion(client_t *client, char **input, size_t nb)
{
    char *goodbye = "221 Goodbye.\r\n";

    (void)input;
    (void)nb;
    write(client->fd, goodbye, strlen(goodbye));
    client->user.username ? free(client->user.username) : 0;
    client->user.username = NULL;
    client->user.password = NULL;
    close(client->fd);
    FD_CLR(client->fd, client->group_fd);
}