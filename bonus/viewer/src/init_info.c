/*
** EPITECH PROJECT, 2024
** AMazeD
** File description:
** initialize info into struct
*/

#include "../../include/viewer.h"

void init_window_info(window_t *w)
{
    w->mode.height = 800;
    w->mode.width = 800;
    w->mode.bitsPerPixel = 32;
    w->window =
    sfRenderWindow_create(w->mode, "Amazed viewer", sfResize | sfClose, NULL);
}

int check_map(void)
{
    maze_t *amaze_td = my_calloc(sizeof(maze_t), 1);
    roomv_t *room = my_calloc(sizeof(roomv_t), 1);
    tunnel_t *tunnel = my_calloc(sizeof(tunnel_t), 1);
    char *buffer = NULL;
    int i = 0;

    if (amaze_td == NULL)
        return ERROR;
    while (1){
        buffer = get_buffer();
        if (buffer == NULL || my_strcmp(buffer, "\0") == 0)
            break;
        buffer = clean_str(buffer);
        init_all_info(buffer, room, tunnel);
        i++;
    }
    return SUCCESS;
}

void init_all_info(char *buffer, roomv_t *r, tunnel_t *t, bot_t *b)
{
    char **num;
    char **words = my_coolersplit(buffer, " ");

    for (int i = 0; words[i] != NULL; i++){
        if (words[i][0] == '#'){
            num = my_split(words[i + 1], ' ');
            r->r_pos.x = my_getnbr(num[1]);
            r->r_pos.y = my_getnbr(num[2]);
            r->tx_room = sfTexture_createFromFile("images/room.png", NULL);
        }
        if (words[i][1] == '-'){
            num = my_split(words[i], '-');
            t->t_pos.x = my_getnbr(num[0]);
            t->t_pos.y = my_getnbr(num[1]);

        }
        if (my_strcmp(words[i], "##start") == 0){
            num = my_split(words[i + 1], ' ');
            b->tx_robot = sfTexture_createFromFile("images/ghost.png", NULL);
            b->b_pos.x = my_getnbr(num[1]);
            b->b_pos.y = my_getnbr(num[2]);
            b->spr_robot = sfSpriteCreate();
        }
    }
}
