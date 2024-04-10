/*
** EPITECH PROJECT, 2024
** maze_t.c
** File description:
** Manage maze_t struct
*/

#include "../../include/maze.h"

void destroy_maze(maze_t *m)
{
    for (size_t i = 0; i < m->room_count; i ++)
        destroy_room(m->room[i]);
    free(m->room);
    free(m->matrix);
    free(m->tunels);
    free(m);
}

int add_maze_matrix(maze_t *m, size_t rooms)
{
    m->room_count = rooms;
    m->matrix = my_calloc(sizeof(bool), rooms * rooms);
    m->tunels = my_calloc(sizeof(bool *), rooms + 1);
    if (m->matrix == NULL || m->tunels == NULL) {
        free(m->matrix);
        free(m->tunels);
        return (0);
    }
    for (size_t i = 0; i < rooms; i ++)
        m->tunels[i] = &m->matrix[i * rooms];
    return (1);
}

void print_matrix(maze_t *m)
{
    if (m->tunels == NULL)
        my_putstr("(null)");
    for (size_t i = 0; i < m->room_count; i++) {
        for (size_t j = 0; j < m->room_count; j ++)
            my_putchar(m->tunels[j][i] + '0');
        my_putchar('\n');
    }
}
