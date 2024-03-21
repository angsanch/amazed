/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step4, display elements of connected list
*/
#include "./graph.h"

void print_data_of_connected_links(link_t *link)
{
    while (link != NULL) {
        printf("%d\n", link->data);
        link = link->next;
    }
}
