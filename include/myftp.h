/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** myftp headers
*/

#ifndef MY_FTP_H
#define MY_FTP_H

#include "ftpstruct.h"

void display_help(char *binary_name);
void error_msg(char *msg);
void error_n_quit(char *msg);
void init_serveur(server_t *serv_ftp, unsigned short port, char *pathfile);
void running_serveur(server_t *serv_ftp);
void close_serveur(server_t *serv_ftp);

#endif /* !MY_FTP_H */
