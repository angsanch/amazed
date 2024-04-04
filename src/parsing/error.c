/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling, read file
*/

#include "../../include/maze.h"


static int check_map(char *path)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1)
        return ERROR;
    free(line);
    return SUCCESS;
}

int error_handling(int argc, char **argv)
{
    if (argc != 1){
        write(2, "Error, invalid amount of arguments.\n", 37);
        return ERROR;
    }
    if (check_map(argv[2]) == ERROR)
        return ERROR;
    return SUCCESS;
}
