/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** All cmd for manage directory in ftp
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ftpstruct.h"
#include "myftp.h"

void pwd(client_t *client, char **input, size_t nb)
{
    char *code = "257\r\n";
    char *err = "530 Please login with USER and PASS.\r\n";

    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    write(client->fd, code, strlen(code));
}

void delete_file(client_t *client, char **input, size_t nb)
{
    char *err = "530 Please login with USER and PASS.\r\n";
    char *del_fail = "550 Perminission denied.\r\n";
    char *del_work = "250 File successfully deleted.\r\n";
    char *file = malloc(sizeof(char) * (strlen(input[1])));

    if (file == NULL)
        error_n_quit("Error: Malloc for deleting file fail.\n");
    for (size_t i = 0; input[1][i] != '\r'; i++)
        file[i] = input[1][i];
    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    if (unlink(file) < 0) {
        write(client->fd, del_fail, strlen(del_fail));
        free(file);
    } else {
        write(client->fd, del_work, strlen(del_work));
        free(file);
    }
}

void change_directory(client_t *client, char **input, size_t nb)
{
    char *err = "530 Please login with USER and PASS.\r\n";
    char *move_dir = "250 Directory successfully changed.\r\n";
    char *err_move = "550 Failed to change directory.\r\n";

    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    if (chdir(input[1]) < 0)
        write(client->fd, err_move, strlen(err_move));
    else {
        write(client->fd, move_dir, strlen(move_dir));
        free(client->path);
        client->path = strdup(input[1]);
    }
}

void change_pdir(client_t *client, char **input, size_t nb)
{
    char *err = "530 Please login with USER and PASS.\r\n";
    char *move_dir = "250 Directory successfully changed.\r\n";
    char *err_move = "550 Failed to change directory.\r\n";
    long size = pathconf("..", _PC_PATH_MAX);
    char *buf;

    if (client->user_ok == false || client->pass_ok == false) {
        write(client->fd, err, strlen(err));
        return;
    }
    if (chdir("..") < 0)
        write(client->fd, err_move, strlen(err_move));
    else {
        write(client->fd, move_dir, strlen(move_dir));
        free(client->path);
        if ((buf = (char *)malloc((size_t)size)) != NULL)
            client->path = getcwd(buf, (size_t)size);
    }
}