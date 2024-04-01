/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling, read file
*/

#include "../include/maze.h"

static int map_size(char *path)
{
    struct stat size;
    int s = 0;

    if (stat(path, &size) != 0)
        return ERROR;
    s = size.st_size;
    return s;
}

static int check_map(char *path)
{
    int fd = open(path, O_RDONLY);
    int size;
    char *buffer;
    size_t rd;

    if (fd == -1)
        return ERROR;
    size = map_size(path);
    if (size < 1)
        return ERROR;
    buffer = malloc(sizeof(char) * size);
    rd = read(fd, buffer, size);
    if ((int)rd == (int)-1)
        return ERROR;
    close (fd);
    return SUCCESS;
}

int error_handling(int argc, char **argv)
{
    if (argc != 2){
        write(2, "Error, invalid amount of arguments.\n", 37);
        return ERROR;
    }
    if (check_map(argv[2]) == ERROR)
        return ERROR;
    return SUCCESS;
}
