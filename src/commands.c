/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** structure containt all commands for my ftp
*/

#include "myftp.h"

const command_t commands[] = {
    {"USER", &user_connexion, "Specify user for authentication\n"},
    {"PASS", &pass_connexion, "Specify password for authentication\n"},
   /* {"CWD", &change_directory, "Change working directory\n"},
    {"CDUP", &change_pdir, "Change working directory to parent directory\n"},
    {"QUIT", &quit, "Disconnection\n"},
    {"DELE", &delete_file, "Delete file on the server\n"},
    {"PWD", &pwd, "Print working directory\n"},
    {"PASV", &passiv_mode, "Enable \"passive\" mode for data transfer\n"},
    {"PORT", &activ_mode, "Enable \"active\" mode for data transfer\n"},
    {"HELP", &help, "List available commands\n"},
    {"NOOP", &noop, "Do nothing\n"},
    {"RETR", &download, "Download file from server to client\n"},
    {"STOR", &upload, "Upload file form client to server\n"},
    {"LIST", &list_file, "List files in the current working directory\n"} */
    {NULL, NULL, NULL}
};