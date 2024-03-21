/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step6, display graph
*/

#include "./graph.h"

void print_my_graph_data(link_t *graph)
{
    while (graph != NULL) {
        printf("%d\n", graph->data);
        graph = graph->next;
    }
}
