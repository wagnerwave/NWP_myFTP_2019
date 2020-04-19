/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** myftp headers
*/

#ifndef MY_FTP_H
#define MY_FTP_H

#include <stdbool.h>
#include "ftpstruct.h"

#define SPACE 32

void display_help(char *binary_name);

void error_msg(char *msg);
void error_n_quit(char *msg);

void user_not_connected(int socket);
void unknown_command(int socket);

void default_client_initialisation(client_t *client);
void init_serveur(server_t *serv_ftp, unsigned short port, char *pathfile);
void init_client(client_t *client, int sock, fd_set *activ_group_fd, server_t *serv_ftp);
void file_transfer_protocol(server_t *serv_ftp);

void interpert_client_input(client_t *client, char *input);

void pass_connexion(client_t *client, char **input, size_t nb);
void user_connexion(client_t *client, char **input, size_t nb);
void quit_connexion(client_t *client, char **input, size_t nb);
void noop(client_t *client, char **input, size_t nb);
void help(client_t *client, char **input, size_t nb);
void pwd(client_t *client, char **input, size_t nb);
void delete_file(client_t *client, char **input, size_t nb);
void change_directory(client_t *client, char **input, size_t nb);

int count_words(char *src, char delim);
char **strtowordarray(char *str, char delim);
char *get_next_line(int fd);

#endif /* !MY_FTP_H */
