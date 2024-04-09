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

typedef struct room_information {
    char *name;
    size_t x;
    size_t y;
} room_t;

typedef struct maze_t_contents {
    size_t bots;//amount of bots
    size_t start;//index of start room_t
    size_t end;//index of end room_t
    size_t room_t_count;//amount of room_ts
    room_t **room_t;//all room_t info
    bool *matrix;
    bool **tunels;//matrix of connections
} maze_t;

maze_t *parse_input(void);//return pointer to maze_t if succesful or NULL if not

//Structs
room_t *create_room_t(char *name, size_t x, size_t y);
void destroy_room_t(room_t *r);
int add_maze_t_matrix(maze_t *m, size_t room_ts);
void destroy_maze_t(maze_t *m);

//functs
char *get_buffer(void);
#endif
