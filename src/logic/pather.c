/*
** EPITECH PROJECT, 2024
** pather.c
** File description:
** Search for shortest path
*/

#include "../../include/maze.h"

path_t *find_short_path(maze_t *m)
{
    bool reached[m->room_count];
    bool active[m->room_count];
    bool activated[m->room_count];

    my_memset(reached, 0, sizeof(reached));
    my_memset(active, 0, sizeof(active));
    my_memset(activated, 0, sizeof(activated));
    return (NULL);
}
