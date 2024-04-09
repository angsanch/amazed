/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling, read file
*/

#include "../../include/maze.h"
#include "../../include/my.h"

char *clean_str(char *line)
{
    my_strreplace(line, "##", "-1");
    for (int i = 0; i != '\n'; i++) {
        if (line[i] == '#')
            line[i] = '\n';
    }
    printf(line);
    return (line);
}

static int check_map(void)
{
    maze *amazed = my_calloc(sizeof(maze), 1);
    char *buffer = NULL;

    if (amazed == NULL)
        return ERROR;
    while (1){
        buffer = get_buffer();
        if (buffer == NULL || my_strcmp(buffer, "\0") == 0)
            break;
        clean_str(buffer);
    }
    return SUCCESS;
}

maze *parse_input(void)
{
    if (check_map() == ERROR)
        return NULL;
    return SUCCESS;
}
