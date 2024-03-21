/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step3, connect two link_t
*/

#include "./graph.h"

void connect_links(link_t *link1, link_t *link2)
{
    link_t *curr;

    if (link1 == NULL)
        link1 = link2;
    else {
        curr = link1;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = link2;
    }
}
