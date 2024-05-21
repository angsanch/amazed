/*
** EPITECH PROJECT, 2024
** pather.c
** File description:
** Search for shortest path
*/

#include "../../include/maze.h"

static void expand_room(maze_t *m, size_t *reached, bool *activated, size_t i)
{
    for (size_t j = 0; j < m->room_count; j ++) {
        if (!m->tunels[i][j])
            continue;
        if (reached[j] > 0)
            continue;
        if (m->room[j]->path != 0)
            continue;
        activated[j] = true;
        reached[j] = reached[i] + 1;
    }
}

static int step_path(maze_t *m, size_t *reached, bool *active, bool *activated)
{
    for (size_t i = 0; i < m->room_count; i ++) {
        if (!active[i])
            continue;
        expand_room(m, reached, activated, i);
    }
    return (activated[m->end] || active[m->end]);
}

static size_t find_previous(maze_t *m, size_t *reached, size_t current)
{
    size_t min = reached[current];
    size_t index = current;

    for (size_t i = 0; i < m->room_count; i ++) {
        if (!m->tunels[current][i])
            continue;
        if (reached[i] < min && reached[i] != 0) {
            min = reached[i];
            index = i;
        }
    }
    return (index);
}

static path_t *build_path(maze_t *m, size_t *reached)
{
    path_t *result = my_calloc(sizeof(path_t), 1);
    size_t *indexes = my_calloc(sizeof(size_t), reached[m->end] + 1);
    ssize_t previous = m->end;
    static int path = 1;

    if (result == NULL || indexes == NULL) {
        free(result);
        free(indexes);
        return (NULL);
    }
    result->nodes = indexes;
    result->len = reached[m->end];
    for (size_t i = 0; i < result->len; i ++) {
        result->nodes[result->len - i - 1] = previous;
        if (previous != m->start && previous != m->end)
            m->room[previous]->path = path;
        previous = find_previous(m, reached, previous);
    }
    path ++;
    return (result);
}

static size_t count_active(maze_t *m, bool *active)
{
    size_t result = 0;

    for (size_t i = 0; i < m->room_count; i ++)
        if (active[i])
            result ++;
    return (result);
}

path_t *find_short_path(maze_t *m)
{
    size_t reached[m->room_count];
    bool active[m->room_count];
    bool activated[m->room_count];
    size_t act;

    my_memset(reached, 0, sizeof(reached));
    my_memset(active, 0, sizeof(active));
    my_memset(activated, 0, sizeof(activated));
    active[m->start] = true;
    reached[m->start] = 1;
    act = 1;
    while (!step_path(m, reached, active, activated) && act) {
        my_memcpy(active, activated, sizeof(active));
        my_memset(activated, 0, sizeof(activated));
        act = count_active(m, active);
    }
    return ((reached[m->end] > 0) ? build_path(m, reached) : NULL);
}
