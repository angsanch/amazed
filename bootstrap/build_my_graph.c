/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** step5, build graph
*/
#include "./graph.h"

link_t *build_my_graph(void)
{
    link_t **graph;

    for (int i = 0; i < 5; i++)
        graph[i] = create_link(i);
    for (int i = 0; graph[i] != NULL; i = 1 + 2)
        connect_links(graph[i], graph[i + 1]);
    return graph[0];
}
