/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step2, display elements
*/

#include "./graph.h"

void print_link(link_t *link)
{
    if (link != NULL)
        printf("%d\n", link->data);
    else
        printf("Error: Invalid link (NULL pointer).\n");
}
