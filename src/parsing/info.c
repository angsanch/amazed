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

void init_info(maze_t *info, char *buffer)
{
    char **num;
    room_t *room;
    char **words = my_coolersplit(buffer, " ");

    for (int i = 0; words[i] != NULL; i++){
        if (words[i][0] == '#'){ //##start, end, room
            num = my_split(words[i + 1], ' ');
            room = create_room(num[0], my_getnbr(num[1]), my_getnbr(num[2]));
            (void)room;
        }
        if (words[i][1] == '-'){ //x-x (tunnel)
            num = my_split(words[i], '-');
            info->tunels[my_getnbr(num[0])][my_getnbr(num[1])] = true;
            info->tunels[my_getnbr(num[1])][my_getnbr(num[0])] = true;
        }
    }
}
