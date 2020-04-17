/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** myftp headers
*/

#ifndef MY_FTP_H
#define MY_FTP_H

#include "ftpstruct.h"

#define SPACE 32

void display_help(char *binary_name);

void error_msg(char *msg);
void error_n_quit(char *msg);

void user_not_connected(int socket);
void unknown_command(int socket);


void init_serveur(server_t *serv_ftp, unsigned short port, char const *pathfile);
void file_transfer_protocol(server_t *serv_ftp);

void interpert_client_input(int socket, char *input, user_t *user);

void pass_connexion(int fd, char **input, size_t nb_w, user_t *user);
void user_connexion(int fd, char **input, size_t nb_w, user_t *user);

int count_words(char *src, char delim);
char **strtowordarray(char *str, char delim);
char *get_next_line(int fd);

#endif /* !MY_FTP_H */
