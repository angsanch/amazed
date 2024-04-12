/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** headerfile
*/

#ifndef MAZE_H_
    #define MAZE_H_
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stddef.h>
    #include "my.h"

    #define ERROR -1
    #define FAIL 84
    #define SUCCESS 0

typedef struct path_information {
    size_t *nodes;
    size_t len;
} path_t;

typedef struct room_information {
    char *name;
    ssize_t x;
    ssize_t y;
    int path;
} room_t;

typedef struct maze_t_contents {
    size_t bots;//amount of bots
    ssize_t start;//index of start room_t
    ssize_t end;//index of end room_t
    size_t room_count;//amount of room_ts
    room_t **room;//all room_t info
    bool *matrix;
    bool **tunels;//matrix of connections
    l_list_t *tunel_lines;
} maze_t;

//tools
room_t *create_room(char *name, size_t x, size_t y);
void destroy_room(room_t *r);
int add_maze_matrix(maze_t *m, size_t rooms);
void print_maze(maze_t *m);
void destroy_maze(maze_t *m);
void destroy_path(path_t *p);

//parser
maze_t *parse_input(void);//return pointer to maze if succesful or NULL if not
char *get_buffer(void);
ssize_t find_room_by_name(maze_t *m, char *name);
char *clean_str(char *line);

//logic
path_t *find_short_path(maze_t *m);

#endif
