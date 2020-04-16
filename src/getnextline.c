/*
** EPITECH PROJECT, 2019
** Get_next_line
** File description:
** gnl for matchstick
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static int new_strlen(char const *str, char c)
{
    int i;

    if (str == NULL)
        return -1;
    for (i = 0; str[i] != '\0' || str[i] == c; i++)
        if (str[i] == c)
            return i;
    return -1;
}

static char *gnl_strndup(char const *src, int i)
{
    char *dest = malloc(new_strlen(src, '\0'));
    int a = 0;

    if (dest == NULL)
        return NULL;
    while (a != i) {
        dest[a] = src[a];
        a++;
    }
    dest[i] = '\0';
    return dest;
}

static char *add_line(char *src, char *buffer)
{
    char *dest = NULL;
    int i = 0;
    int j = 0;
    int len = src ? new_strlen(src, '\0') : 0;
    int a = buffer ? new_strlen(buffer, '\0') : 0;

    dest = malloc(sizeof(char) * (a + len + 1));
    if (dest == NULL)
        return NULL;
    for (j = 0; src && src[j]; j++)
        dest[j] = src[j];
    for (i = 0; buffer[i] != '\0'; i++)
        dest[i + j] = buffer[i];
    dest[i + j] = '\0';
    return dest;
}

char *get_next_line(int fd)
{
    char stock[1024];
    static char *cur_line = NULL;
    char *ret = NULL;
    int size_r = 0;
    int i = 0;

    while (new_strlen(cur_line, '\n') == -1) {
        size_r = read(fd, stock, 1024);
        stock[size_r] = '\0';
        if (size_r <= 0) {
            cur_line = NULL;
            ret = cur_line;
            return ret;
        }
        if ((cur_line = add_line(cur_line, stock)) == NULL)
            return NULL;
    }
    i = new_strlen(cur_line, '\n');
    ret = gnl_strndup(cur_line, i);
    cur_line = gnl_strndup(cur_line + i + 1, new_strlen(cur_line + i, '\0'));
    return ret;
}
