/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** Helper functions for parsing
*/

#include "../../include/maze.h"

static int true_replace(char **base, char *key, char *replace)
{
    char *old = *base;

    *base = my_strreplace(*base, key, replace);
    if (*base == NULL) {
        *base = old;
        return (0);
    }
    free(old);
    return (1);
}

char *clean_str(char *line)
{
    char *clean;
    char negs[2] = "\0\0";

    negs[0] = -1;
    if (!true_replace(&line, "##start", negs))
        return NULL;
    negs[0] = -2;
    if (!true_replace(&line, "##end", negs))
        return NULL;
    clean = my_strchr(line, '#');
    if (clean != NULL)
        clean[0] = '\0';
    return (line);
}

char *get_buffer(void)
{
    char *buffer = NULL;
    ssize_t len = 0;

    len = getline(&buffer, (size_t *)&len, stdin);
    if (len < 0) {
        free(buffer);
        return NULL;
    }
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    for (int i = 0; i < len; i++)
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    buffer = clean_str(buffer);
    return (buffer);
}

ssize_t find_room_by_name(maze_t *m, char *name)
{
    for (size_t i = 0; i < m->room_count; i ++) {
        if (my_strcmp(m->room[i]->name, name) == 0)
            return (i);
    }
    return (-1);
}
