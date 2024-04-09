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
    line = my_strreplace(line, "##", "\255");
    for (int i = 0; i != '\n'; i++) {
        if (line[i] == '#')
            line[i] = '\n';
    }
    my_printf("%s", line);
    return (line);
}

static int check_map(void)
{
    maze *amazed = my_calloc(sizeof(maze), 1);
    char *buffer = NULL;
    int i = 0;

    if (amazed == NULL)
        return ERROR;
    while (1){
        buffer = get_buffer();
        if (buffer == NULL || my_strcmp(buffer, "\0") == 0)
            break;
        buffer = clean_str(buffer);
        my_printf("%d\n", i);
        i++;
    }
    return SUCCESS;
}

maze *parse_input(void)
{
    if (check_map() == ERROR)
        return NULL;
    return SUCCESS;
}
