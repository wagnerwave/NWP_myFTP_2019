/*
** EPITECH PROJECT, 2018
** nom de projet
** File description:
** coucou
*/

#include <stdlib.h>

int count_words(char *src, char delim)
{
        int nb_w = 1;
        int i = 0;

        if (src == NULL)
                return (0);
        while (src[i] != '\0') {
                if (src[i] == delim)
                        nb_w++;
                i++;
        }
        return (nb_w);
}

static int my_wordlen(char *src, char delim)
{
        int i = 0;

        while (src[0] != delim && src[0] != '\0') {
                i++;
                src++;
        }
        return (i);
}

char **strtowordarray(char *str, char delim)
{
        int i = 0;
        int j = 0;
        int len = 0;
        char **tab;
        int nb = count_words(str, delim);

        if (nb < 0 || !(tab = malloc(sizeof(char *) * (nb + 1))))
            return (NULL);
        for (; i < nb; i++) {
            len = my_wordlen(str, delim);
            if (!(tab[i] = malloc(sizeof(char) * (len + 2))))
                return (NULL);
            for (j = 0; j < len; j++ , str++)
                tab[i][j] = *str;
            str++;
            tab[i][j] = '\0';
        }
        tab[i] = NULL;
        return (tab);
}
