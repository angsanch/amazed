/*
** EPITECH PROJECT, 2024
** printer.c
** File description:
** Print paths
*/

#include "../../include/maze.h"

/*static void print_rango(size_t a, size_t b, path_t *p, maze_t *m)
{
    if (a < b) {
        putchar('P');
        for (size_t i = a; i <= b; i++) {
            my_printf("%s", m->room[p->nodes[a]]->name);
        }
    }
} */

int move_path(maze_t *m, path_t *p)
{
    (void) m;
    size_t begining = p->bots;
    begining = begining - 1;
    p->traveling = p->traveling + 1;
    return (0);
}