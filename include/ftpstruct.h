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

typedef struct user_s {
    char username[20];
    char password[30];
} user_t;

typedef struct ftpstruct_s {
    user_t user;
    struct sockaddr_in sin;
    int tcp_socket;
    int new_tcp_socket;
    unsigned short port;
    char *home;
} server_t;

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

typedef enum status_socket_e {
    SOCKET_NONE_INIT = 00000,
    SOCKET_DONE = 00001,
    SOCKET_NOT_READY = 00010,
    SOCKET_PARTIAL = 00100,
    SOCKET_DISCONNECTED = 01000,
    SOCKET_ERR = 10000
} status_socket_t;

#endif /* !FTR_STRUCT_H_ */
