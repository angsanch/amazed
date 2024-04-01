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

    #define ERROR -1
    #define FAIL 84
    #define SUCCESS 0

typedef struct info {
    int robots;
    char **rooms;
    char **start;
    char **tunnels;
} info_t;

int error_handling(int argc, char **argv);

#endif
