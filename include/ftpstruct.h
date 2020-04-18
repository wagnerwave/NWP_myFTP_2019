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
#include <sys/time.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_CONNECTION_SERVER 20

typedef struct user_s {
    char *username;
    char *password;
} user_t;

typedef struct ftpstruct_s {
    struct sockaddr_in sin;
    int tcp_socket;
    unsigned short port;
    char const *dir;
} server_t;

typedef struct client_s {
    user_t user;
    int fd;
    fd_set *group_fd;
    bool user_ok;
    bool pass_ok;
}  client_t;

typedef struct command_s {
    char *cmd;
    void (*func)(client_t *, char **, size_t);
    char *desc;
} command_t;

extern const command_t commands[];

#endif /* !FTR_STRUCT_H_ */
