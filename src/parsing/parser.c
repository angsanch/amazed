/*
** EPITECH PROJECT, 2024
** parser.c
** File description:
** Parse the input
*/

#include "../../include/maze.h"

static int get_mazed_int(char *str)
{
    int result = my_getnbr(str);

    if ((size_t)my_intlen(result) != my_strlen(str) || !my_str_isnum(str))
        return (-1);
    return (result);
}

static int start_maze(maze_t *m)
{
    char *line = get_buffer();
    int bots;

    if (line == NULL)
        return (report_error("Unable to get next line\n", 0));
    bots = get_mazed_int(line);
    free(line);
    if (bots < 0)
        return (report_error("Invalid amount of numbers\n", 0));
    m->bots = bots;
    m->start = -1;
    m->end = -1;
    return (1);
}

static int link_room(maze_t *m, l_list_t *l, char **parts)
{
    room_t *r = create_room(parts[0],
        get_mazed_int(parts[1]), get_mazed_int(parts[2]));

    if (r == NULL)
        return (report_error("Memory problem creating room\n", 0));
    if (r->x < 0 || r->y < 0 || find_room_by_name(m, parts[0]) >= 0) {
        destroy_room(r);
        my_dprintf(2, "Inavalid room information. (%zd)\n", l->len);
        return (0);
    }
    r->index = l->len;
    if (!list_append(l, r)) {
        destroy_room(r);
        return (report_error("Memory problem appending room\n", 0));
    }
    return (1);
}

static int add_startend(maze_t *m, char *str, size_t len)
{
    ssize_t *num = NULL;

    if (str[0] >= 0 || my_strlen(str) != 1)
        return (report_error("Invalid line parameters.\n", 0));
    switch (str[0]) {
        case -1:
            num = &m->start;
            break;
        case -2:
            num = &m->end;
            break;
        default:
            return (report_error("Invalid char.\n", 0));
    }
    if (*num != -1)
        return (report_error("Start or end was already set.\n", 0));
    *num = len;
    return (1);
}

static int add_room(maze_t *m, l_list_t *l, char *line)
{
    char **parts;
    size_t len;
    int status = 0;

    parts = my_split(line, ' ');
    free(line);
    if (parts == NULL)
        return (report_error("Memory problem splitting line.", 0));
    len = get_pointer_array_len(parts);
    if (len == 1)
        status = add_startend(m, parts[0], l->len);
    if (len == 3)
        status = link_room(m, l, parts);
    if (len == 0)
        status = 1;
    free_string_array(parts);
    return (status);
}

static int add_rooms(maze_t *m, l_list_t *l, char **line)
{
    while (true) {
        *line = get_buffer();
        if (*line == NULL)
            return (report_error("Unable to get next line\n", 0));
        if (my_strchr(*line, '-'))
            break;
        if (!add_room(m, l, *line))
            return (report_error("Error adding room.\n", 0));
    }
    if (!add_maze_matrix(m, l->len)) {
        free(line);
        return (report_error("Memory error creating matrix.\n", 0));
    }
    m->room = (room_t **)list_export(l, NULL);
    if (m->room)
        list_unlink(l);
    free((m->room) ? NULL : *line);
    return (m->room != NULL);
}

static int process_tunel(maze_t *m, char **parts)
{
    ssize_t ind1;
    ssize_t ind2;

    if (get_pointer_array_len(parts) != 2)
        return (report_error("Invalid amount of values for a tunel.\n", 0));
    ind1 = find_room_by_name(m, parts[0]);
    if (ind1 < 0)
        return (report_error("Invalid first value for tunel.\n", 0));
    ind2 = find_room_by_name(m, parts[1]);
    if (ind2 < 0)
        return (report_error("Invalid second value for tunel.\n", 0));
    if (m->tunels[ind1][ind2] || m->tunels[ind2][ind1])
        return (report_error("Tunel already existed.\n", 0));
    m->tunels[ind1][ind2] = true;
    m->tunels[ind2][ind1] = true;
    return (1);
}

static int process_tunels(maze_t *m, char *prev_line)
{
    char *line = prev_line;
    char **parts;
    int result;

    while (true) {
        if (line == NULL)
            return (1);
        parts = my_split(line, '-');
        free(line);
        if (parts == NULL)
            return (report_error("Invalid first value for tunel.\n", 0));
        result = process_tunel(m, parts);
        free_string_array(parts);
        if (!result)
            return (report_error("Error adding tunel.\n", 0));
        line = get_buffer();
    }
}

static int fill_maze(maze_t *m)
{
    l_list_t *l;
    int room;
    char *last_line;

    if (!start_maze(m))
        return (report_error("Error starting maze.\n", 0));
    l = list_create(&free);
    if (l == NULL)
        return (report_error("Memory error creating list.\n", 0));
    room = add_rooms(m, l, &last_line);
    list_destroy(l);
    if (m->start == -1 || m->end == -1 || (size_t)m->start >= m->room_count ||\
        (size_t)m->end >= m->room_count || !room) {
        free(last_line);
        return (report_error("Unavailable or invalid data in maze.\n", 0));
    }
    return (process_tunels(m, last_line));
}

maze_t *parse_input(void)
{
    maze_t *m = my_calloc(sizeof(maze_t), 1);

    if (m == NULL)
        return (NULL);
    if (!fill_maze(m)) {
        destroy_maze(m);
        return (NULL);
    }
    print_maze(m);
    return (m);
}
