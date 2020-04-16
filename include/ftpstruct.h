/*
** EPITECH PROJECT, 2020
** Alexandre Wagner
** File description:
** ftp global struct
*/

#ifndef FTR_STRUCT_H_
#define FTR_STRUCT_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CONNECTION_SERVER 20

typedef struct user_s {
    char *username;
    char *password;
} user_t;

typedef struct ftpstruct_s {
    user_t user;
    struct sockaddr_in sin;
    int tcp_socket;
    unsigned short port;
    char const *dir;
} server_t;

typedef struct command_s {
    char *cmd;
    int (*func)(int, int, char **);
    char *desc;
} command_t;

typedef enum serv_status_e {
    SERVICE_READY = 120,
    TRANSFER_DATA = 125,
    CMD_OK = 200,
    HELP = 214,
    READY_FOR_NEW_USER = 220,
    SERVICE_CLOSE = 221,
    CLOSING_DATA = 226,
    PASSIVE_MODE = 227,
    USER_LOGGED = 230,
    PATH_CREATED = 257,
    NEED_PASSWD = 331,
    NEED_USER = 332
} serv_status_t;

#endif /* !FTR_STRUCT_H_ */
