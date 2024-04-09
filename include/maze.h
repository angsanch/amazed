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
} room;

typedef struct maze_contents {
    size_t bots;//amount of bots
    size_t start;//index of start room
    size_t end;//index of end room
    size_t room_count;//amount of rooms
    room **room;//all room info
    bool *matrix;
    bool **tunels;//matrix of connections
} maze;

maze *parse_input(void);//return pointer to maze if succesful or NULL if not

//Structs
room *create_room(char *name, size_t x, size_t y);
void destroy_room(room *r);
maze *create_maze(size_t rooms);
void destroy_maze(maze *m);

//functs
char *get_buffer(void);
#endif
