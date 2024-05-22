/*
** EPITECH PROJECT, 2024
** printer.c
** File description:
** Print paths
*/

#include "../../include/maze.h"

static void print_range(maze_t *m, path_t *p, ssize_t a, ssize_t b)
{
    size_t robot_id = p->arrived + p->lowest_id;

    for (ssize_t i = b; i > a; i --) {
        my_printf("P%zd-%s%s", robot_id,
            m->room[p->nodes[i]]->name, (i - 1 > a) ? " " : "");
        robot_id ++;
    }
}

int move_path(maze_t *m, path_t *p)
{
    if (p->bots == p->arrived)
        return (0);
    if (p->waiting == 0)
        p->tail ++;
    else {
        p->waiting --;
        p->traveling ++;
    }
    if (p->tail + p->traveling >= p->len) {
        p->traveling --;
        p->arrived ++;
    }
    if (p->bots == p->arrived)
        return (0);
    print_range(m, p, p->tail, p->tail + p->traveling);
    return (1);
}
