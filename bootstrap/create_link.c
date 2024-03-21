/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step1, add element to linked list
*/

#include "./graph.h"

link_t *create_link(int data)
{
    link_t *temp = malloc(sizeof(link_t));

    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}
