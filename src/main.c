/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main funct
*/

#include "../include/maze.h"

int main(int argc, char **argv)
{
    for (int i = 0; argv[i] != NULL; i++)
        printf("%s\n", argv[i]);
    //printf("%s", argv[2]);
    if (error_handling(argc, argv) == ERROR)
        return FAIL;
    return SUCCESS;
}
