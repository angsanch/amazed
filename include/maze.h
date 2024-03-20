/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** headerfile
*/

#ifndef A_MAZE_D_
    #define A_MAZE_D_
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stddef.h>

typedef struct info {
    int robots;
    char *rooms;
    char *start;
    char *tunnels;
} info_t;

#endif
