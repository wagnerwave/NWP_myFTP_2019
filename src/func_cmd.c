/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** Function for FTP command
*/

#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "ftpstruct.h"
#include "myftp.h"

static bool check_if_user_is_connected(user_t *user)
{
    if (user->username == NULL)
        return false;
    if (strcmp(user->username, "anonymous") == 0 &&
        strcmp(user->password, "") == 0)
        return true;
    return false;
}

void user_connexion(int fd, char **input, size_t nb_w, user_t *user)
{
    char *err_msg = "530 Can't change from guest user.\n";
    char *perm_err = "530 Permission denied.\n";
    char *ok = "331 Please specify the password.\n";

    if (check_if_user_is_connected(user) == true)  {
        write(fd, err_msg, strlen(err_msg));
        return;
    }
    if (nb_w == 1) {
        write(fd, perm_err, strlen(perm_err));
        return;
    }
    user->username = strdup(input[1]);
    write(fd, ok, strlen(ok));
}

void pass_connexion(int fd, char **input, size_t nb_w, user_t *user)
{
    char *already_con = "230 Already logged in.\n";
    char *ok = "230 Login successful.\n";
    char *err = "530 Login incorrect.\n";

    (void)input;
    (void)nb_w;
    if (check_if_user_is_connected(user) == true) {
        write(fd, already_con, strlen(already_con));
        return;
    }
    user->password = "";
    if (!strcmp(user->username, "anonymous"))
        write(fd, ok, strlen(ok));
    else
        write(fd, err, strlen(err));
}