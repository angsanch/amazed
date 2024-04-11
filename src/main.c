/*
** EPITECH PROJECT, 2024
** amaze_td
** File description:
** main funct
*/

#include "../include/maze.h"

/*
void file_to_stdin(void)
{
    close(0);
    open("tests/labyrinth1", O_RDONLY);
}
*/

int main(int argc, char **)
{
    maze_t *m;

    if (argc != 1)
        return (report_error("This program doesnt need parameter_ts\n", 84));
    m = parse_input();
    if (m == NULL)
        return (report_error("Error preparing maze_t.\n", 84));
    destroy_maze(m);
    return (0);
}
