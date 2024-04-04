/*
** EPITECH PROJECT, 2024
** maze.c
** File description:
** Manage maze struct
*/

#include "../../include/maze.h"

void destroy_maze(maze *m)
{
    for (size_t i = 0; i < m->room_count; i ++) {
        destroy_room(m->room[i]);
        free(m->tunels[i]);
    }
    free(m->room);
    free(m->tunels);
    free(m);
}
