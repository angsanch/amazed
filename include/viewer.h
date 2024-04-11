/*
** EPITECH PROJECT, 2024
** AMazeD
** File description:
** header file
*/

#ifndef VIEWER_H
    #define VIEWER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Sensor.h>
    #include "../../include/maze.h"

//struct for the CSFML
typedef struct window {
    sfRenderWindow *window;
    // sfTexture *tx_background;
    // sfSprite *spr_background;
    sfVideoMode mode;
    sfEvent event;
} window_t;
typedef struct bot {
    sfTexture *tx_robot;
    sfSprite *spr_robot;
    sfVector2f b_pos;
    struct bot *next;
} bot_t;
typedef struct roomv {
    sfTexture *tx_room;
    sfSprite *spr_room;
    sfVector2f r_pos;
    struct roomv *next;
} roomv_t;
typedef struct tunnel {
    sfTexture *tx_tunnel;
    sfSprite *spr_tunnel;
    sfVector2f t_pos;
    struct tunnel *next;
} tunnel_t;

void init_window_info(window_t *w);
void init_all_info(char *buffer, roomv_t *r, tunnel_t *t, bot_t *b);
int window(window_t *window, tunnel_t **tunnel, bot_t **bot, roomv_t **room);
int check_map(void);
#endif
