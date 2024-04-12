/*
** EPITECH PROJECT, 2024
** path_chooser.c
** File description:
** Choose what paths to use
*/

#include "../../include/maze.h"

static size_t total_conections(maze_t *m, size_t index)
{
    size_t total = 0;

    for (size_t i = 0; i < m->room_count; i ++)
        if (m->tunels[index][i])
            total ++;
    return (total);
}

static size_t get_max_paths(maze_t *m)
{
    size_t start = total_conections(m, m->start);
    size_t end = total_conections(m, m->end);

    return ((start >= end) ? start : end);
}

static void free_all_paths(path_t **paths)
{
    for (size_t i = 0; paths[i] != NULL; i ++)
        destroy_path(paths[i]);
}

static size_t spread_bots(maze_t *m, path_t **paths, size_t path_count)
{
    size_t turns = paths[0]->len + 1;
    size_t remaining = m->bots;
    size_t total = 0;
    int added;

    while (remaining > 0) {
        for (size_t i = 0; i < path_count && remaining > 0; i ++) {
            added = (turns >= paths[i]->len) ? 1 : 0;
            paths[i]->bots += added;
            remaining -= added;
        }
        turns ++;
    }
    for (total = 0; paths[total] != NULL && total < path_count; total ++) {
        if (paths[total]->bots == 0)
            break;
        paths[total]->waiting = paths[total]->bots;
    }
    return (total);
}

void open_the_gates(maze_t *m, path_t **paths, size_t path_count)
{
    size_t paths_moved = 0;
    int moved = 1;

    my_printf("%s\n", "#moves");
    while (moved > 0) {
        paths_moved = 0;
        for (size_t i = 0; i < path_count; i ++) {
            moved = move_path(m, paths[i]);
            paths_moved += moved;
            my_putstr((moved && i < path_count - 1) ? " " : "");
        }
        my_putstr((paths_moved) ? "\n" : "");
    }
}

int move_bots(maze_t *m)
{
    size_t max_paths = get_max_paths(m);
    size_t path_count = 0;
    path_t *paths[max_paths + 1];

    my_memset(paths, 0, sizeof(paths));
    for (path_count = 0; path_count < max_paths; path_count ++) {
        paths[path_count] = find_short_path(m);
        if (paths[path_count] == NULL)
            break;
    }
    if (paths[0] == NULL)
        return (report_error("Unable to create any path.\n", 0));
    path_count = spread_bots(m, paths, path_count);
    open_the_gates(m, paths, path_count);
    free_all_paths(paths);
    return (1);
}
