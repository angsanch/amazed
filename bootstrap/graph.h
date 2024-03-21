/*
** EPITECH PROJECT, 2024
** bs a-maze-d
** File description:
** header file
*/
#ifndef BS_AMAZED_
    #define BS_AMAZED_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct link {
    int data;
    struct link *next;
} link_t;

link_t *create_link(int data);
void print_link(link_t *link);

#endif
