/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main funct
*/

#include "../include/maze.h"

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == ERROR)
        return FAIL;
    return SUCCESS;
}
