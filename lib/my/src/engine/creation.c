/*
** EPITECH PROJECT, 2023
** creation.c
** File description:
** Allocate and prepare the structs
*/

#include "../../include/my.h"
#include "../../include/engine_utils.h"

static char *path2id(char const *path)
{
    char *result;
    char const *start;
    ssize_t len;

    start = my_strrchr(path, '/');
    if (start == NULL)
        start = path;
    else
        start ++;
    len = my_strchr_index(start, '.');
    if (len == -1)
        len = my_strlen(start);
    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    my_memcpy(result, start, len);
    result[len] = '\0';
    return (result);
}

dn_texture *create_texture(dn_scene *scene, char const *path,
    size_t x_tiles, size_t y_tiles)
{
    dn_texture *texture = malloc(sizeof(dn_texture) * 1);

    if (texture == NULL)
        return (NULL);
    texture->texture = sfTexture_createFromFile(path, NULL);
    if (texture->texture == NULL){
        free(texture);
        return (NULL);
    }
    if (!list_append(scene->textures, texture)){
        free(texture);
        return (NULL);
    }
    texture->id = path2id(path);
    texture->x_tiles = x_tiles;
    texture->y_tiles = y_tiles;
    return (texture);
}

static void set_sprite_display(dn_display_info *display)
{
    display->rotate_texture = 1;
    display->rotate_outline = 1;
    display->texture = NULL;
    display->draw_texture = true;
    display->outline = sfRectangleShape_create();
    sfRectangleShape_setFillColor(display->outline, (sfColor){0, 0, 0, 0});
    display->outline_color = sfBlack;
    display->outline_size = (sfVector2f){0, 0};
    display->draw_outline = false;
    display->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(display->circle, (sfColor){0, 0, 0, 0});
    display->circle_color = sfBlack;
    display->circle_size = 0;
    display->draw_circle = false;
}

dn_sprite *create_sprite(dn_scene *scene)
{
    dn_sprite *sprite = malloc(sizeof(dn_sprite) * 1);

    if (sprite == NULL)
        return (NULL);
    if (!list_append(scene->sprites, sprite)){
        free(sprite);
        return (NULL);
    }
    sprite->id = scene->id_sprite;
    scene->id_sprite += 1;
    sprite->sprite = sfSprite_create();
    set_sprite_display(&sprite->display);
    sprite->tick = NULL;
    sprite->event = NULL;
    sprite->destroy_data = NULL;
    sprite->data = NULL;
    sprite->position = (sfVector2f){0, 0};
    sprite->angle = 0;
    sprite->collision = 0;
    return (sprite);
}

dn_scene *create_scene(char const *id)
{
    dn_scene *scene = malloc(sizeof(dn_scene) * 1);

    if (scene == NULL)
        return (NULL);
    scene->music = NULL;
    scene->id_sprite = 0;
    scene->sprites = list_create(&destroy_sprite);
    scene->textures = list_create(&destroy_texture);
    scene->creation = NULL;
    if (scene->sprites == NULL || scene->textures == NULL){
        destroy_scene(scene);
        return (NULL);
    }
    scene->id = my_strdup(id);
    return (scene);
}

dn_window *create_window(int width, int height, char *name, sfUint32 style)
{
    sfVideoMode mode = {width, height, 32};
    dn_window *window = malloc(sizeof(dn_window) * 1);

    if (window == NULL)
        return (NULL);
    window->window = sfRenderWindow_create(mode, name, style, NULL);
    window->scene = NULL;
    window->resolution = (sfVector2i){width, height};
    window->size = (sfVector2i){width, height};
    window->scenes = list_create(&destroy_scene);
    if (window->scenes == NULL){
        free(window);
        return (NULL);
    }
    window->to_be_closed = false;
    window->clock = sfClock_create();
    window->scene = create_scene("master");
    window->manage_collision = NULL;
    return (window);
}
