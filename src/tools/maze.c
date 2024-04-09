/*
** EPITECH PROJECT, 2024
** maze_t.c
** File description:
** Manage maze_t struct
*/

#include "../../include/maze.h"

void destroy_maze_t(maze_t *m)
{
    for (size_t i = 0; i < m->room_t_count; i ++)
        destroy_room_t(m->room_t[i]);
    free(m->room_t);
    free(m->matrix);
    free(m->tunels);
    free(m);
}

int add_maze_t_matrix(maze_t *m, size_t room_ts)
{
    m->room_t_count = room_ts;
    m->matrix = my_calloc(sizeof(bool), room_ts * room_ts);
    m->tunels = my_calloc(sizeof(bool *), room_ts + 1);
    if (m->matrix == NULL || m->tunels == NULL) {
        free(m->matrix);
        free(m->tunels);
        return (ERROR);
    }
    for (size_t i = 0; i < room_ts; i ++)
        m->tunels[i] = &m->matrix[i * room_ts];
    return (SUCCESS);
}
