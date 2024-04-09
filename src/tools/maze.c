/*
** EPITECH PROJECT, 2024
** maze.c
** File description:
** Manage maze struct
*/

#include "../../include/maze.h"

void destroy_maze(maze *m)
{
    for (size_t i = 0; i < m->room_count; i ++)
        destroy_room(m->room[i]);
    free(m->room);
    free(m->matrix);
    free(m->tunels);
    free(m);
}

int add_maze_matrix(maze *m, size_t rooms)
{
    m->room_count = rooms;
    m->matrix = my_calloc(sizeof(bool), rooms * rooms);
    m->tunels = my_calloc(sizeof(bool *), rooms + 1);
    if (m->matrix == NULL || m->tunels == NULL) {
        free(m->matrix);
        free(m->tunels);
        return (ERROR);
    }
    for (size_t i = 0; i < rooms; i ++)
        m->tunels[i] = &m->matrix[i * rooms];
    return (SUCCESS);
}
