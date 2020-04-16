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
void init_serveur(server_t *serv_ftp, unsigned short port, char const *pathfile);
void file_transfer_protocol(server_t *serv_ftp);
void close_serveur(int fd);
void interpert_client_input(int socket, char *buffer);
void unknown_command(int socket);
char **strtowordarray(char *str, char delim);

#endif /* !MY_FTP_H */
