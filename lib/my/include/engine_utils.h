/*
** EPITECH PROJECT, 2023
** engine_utils.h
** File description:
** Engine tools
*/

#ifndef ENGINE_UTILS_H_
    #define ENGINE_UTILS_H_

    #include "structs.h"

typedef struct collision_quarter {
    dn_sprite_t **sprites;
    size_t amount;
    sfIntRect *rect;
} quarter_info_t;

void destroy_sound(void *sound);
void destroy_texture(void *texture);
void destroy_sprite(void *sprite);
void destroy_scene(void *scene);
void collisions(dn_window_t *window);

#endif
