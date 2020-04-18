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

static bool check_if_user_is_connected(client_t *client)
{
    if (client->user.username != NULL && client->user.password != NULL)
        return true;
    return false;
}

void user_connexion(client_t *client, char **input, size_t nb)
{
    char *err_msg = "530 Can't change from guest user.\n";
    char *perm_err = "530 Permission denied.\n";
    char *ok = "331 Please specify the password.\n";

    if (check_if_user_is_connected(client))  {
        write(client->fd, err_msg, strlen(err_msg));
        return;
    }
    if (nb == 1) {
        write(client->fd, perm_err, strlen(perm_err));
        return;
    }
    client->user.username = strdup(input[1]);
    write(client->fd, ok, strlen(ok));
}

void pass_connexion(client_t *client, char **input, size_t nb)
{
    char *already_con = "230 Already logged in.\n";
    char *ok = "230 Login successful.\n";
    char *err = "530 Login incorrect.\n";
    char *user_first = "503 Login with USER first.\n";

    (void)nb;
    if (client->user.username == NULL) {
        write(client->fd, user_first, strlen(user_first));
        return;
    }
    if (check_if_user_is_connected(client)) {
        write(client->fd, already_con, strlen(already_con));
        return;
    }
    client->user.password = "";
    if (strcmp(client->user.username, "anonymous") == 0)
        write(client->fd, ok, strlen(ok));
    else {
        write(client->fd, err, strlen(err));
        client->user.username ? free(client->user.username) : 0;
        client->user.username = NULL;
    }
}

void quit_connexion(client_t *client, char **input, size_t nb)
{
    char *goodbye = "221 Goodbye.\n";

    write(client->fd, goodbye, strlen(goodbye));
    client->user.username ? free(client->user.username) : 0;
    client->user.username = NULL;
    client->user.password = NULL;
    close(client->fd);
    FD_CLR(client->fd, client->group_fd);
}