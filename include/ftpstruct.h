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

typedef struct ftpstruct_s {
    struct sockaddr_in sin;
    int tcp_socket;
    unsigned short port;
    char *home;
} server_t;

#endif /* !FTR_STRUCT_H_ */
