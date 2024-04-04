/*
** EPITECH PROJECT, 2024
** rooms.c
** File description:
** Manage room structs
*/

#include "../../include/maze.h"

room *create_room(char *name, size_t x, size_t y)
{
    room *r = malloc(sizeof(room) * 1);

    if (r == NULL)
        return (NULL);
    r->name = my_strdup(name);
    if (r->name == NULL) {
        free(r);
        return (NULL);
    }
    r->x = x;
    r->y = y;
    return (r);
}

void destroy_room(room *r)
{
    if (r == NULL)
        return;
    free(r->name);
    free(r);
}
