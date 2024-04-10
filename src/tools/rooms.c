/*
** EPITECH PROJECT, 2024
** room_ts.c
** File description:
** Manage room_t structs
*/

#include "../../include/maze.h"

room_t *create_room(char *name, size_t x, size_t y)
{
    room_t *r = malloc(sizeof(room_t) * 1);

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

void destroy_room(room_t *r)
{
    if (r == NULL)
        return;
    free(r->name);
    free(r);
}
