/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling, read file
*/

#include "../../include/maze.h"
#include "../../include/my.h"

char *get_buffer(void)
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

char *clean_str(char *line)
{
    my_strreplace(line, "##", "-1");
    for(int i = 0; i != '\n'; i++) {
        if (line[i] == '#')
            line[i] = '\n';
    }
    printf(line);
    return(line);
}

static int check_map()
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

int error_handling(int argc)
{
    if (argc != 1){
        write(2, "Error, invalid amount of arguments.\n", 37);
        return ERROR;
    }
    if (check_map() == ERROR)
        return ERROR;
    return SUCCESS;
}
