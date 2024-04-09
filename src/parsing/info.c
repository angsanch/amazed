/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling, read file
*/

#include "../../include/maze.h"
#include "../../include/my.h"

char *get_buffer(int nline)
{
    char *buffer = NULL;
    int err = 0;
    size_t len;

    err = getline(&buffer, &len, stdin);
    if (err < 0)
        return NULL;
    if (buffer[err - 1] == '\n')
        buffer[err - 1] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    return (buffer);
}

void init_info()
{

}