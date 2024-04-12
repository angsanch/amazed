/*
** EPITECH PROJECT, 2024
** maze_t.c
** File description:
** Manage maze_t struct
*/

#include "../../include/maze.h"

static void printer(char *str)
{
    if (str == NULL)
        return;
    my_printf("%s\n", str);
}

void print_maze(maze_t *m)
{
    my_printf("%s\n%zd\n%s\n", "#number_of_robots", m->bots, "#rooms");
    for (size_t i = 0; m->room_count > i; i++){
        if (i == (size_t)m->start)
            my_putstr("##start\n");
        if (i == (size_t)m->end)
            my_putstr("##end\n");
        my_printf("%s %d %d\n", m->room[i]->name,
        m->room[i]->x, m->room[i]->y);
    }
    my_putstr("#tunnels\n");
    list_iter(m->tunel_lines, (void *)printer, NULL);
}

void destroy_maze(maze_t *m)
{
    for (size_t i = 0; i < m->room_count; i ++)
        destroy_room(m->room[i]);
    free(m->room);
    free(m->matrix);
    free(m->tunels);
    list_destroy(m->tunel_lines);
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
