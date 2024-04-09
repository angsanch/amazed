/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main funct
*/

#include "../include/maze.h"

int main(int argc, char **)
{
    if (error_handling(argc) == ERROR)
        return FAIL;
    return SUCCESS;
}
