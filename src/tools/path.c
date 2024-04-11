/*
** EPITECH PROJECT, 2024
** path.c
** File description:
** Manage path
*/

#include "../../include/maze.h"

void destroy_path(path_t *p)
{
    if (p == NULL)
        return;
    free(p->nodes);
    free(p);
}
