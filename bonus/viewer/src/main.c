/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** main
*/

#include "../../../include/viewer.h"

void work(window_t *w, tunnel_t **tunnel, bot_t **bot, roomv_t **room)
{
    char *buffer = get_buffer();

    if (check_map() == 0) {
        init_window_info(w);
        init_all_info(buffer, *room, *tunnel, *bot);
        window(w, tunnel, bot, room);
        free(w);
        free(*tunnel);
        free(*bot);
        free(*room);
    }
}

int main(int argc, char **argv)
{
    window_t *window = malloc(sizeof(window_t));
    tunnel_t *tunnel = NULL;
    bot_t *bot = NULL;
    roomv_t *room = NULL;

    if (argc == 2) {
        work(window, &tunnel, &bot, &room);
        return SUCCESS;
    } else
        return ERROR;
    return SUCCESS;
}
