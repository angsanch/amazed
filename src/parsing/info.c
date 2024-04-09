/*
** EPITECH PROJECT, 2024
** amaze_td
** File description:
** error handling, read file
*/

#include "../../include/maze.h"
#include "../../include/my.h"

char *get_buffer(void)
{
    char *buffer = NULL;
    int len = 0;
    size_t size = 0;

    len = getline(&buffer, &size, stdin);
    if (len < 0)
        return NULL;
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    return (buffer);
}

void init_info()
{

}
