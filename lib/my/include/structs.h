/*
** EPITECH PROJECT, 2023
** structs.h
** File description:
** Structs for libmy
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct file_buffer_t_container {
    char *buffer;
    size_t buff_len;
    char *line;
    ssize_t len;
} file_buffer_t;

typedef struct linked_list_element {
    void *content;
    struct linked_list_element *next;
} l_elem_t;
typedef struct linked_list_container {
    size_t len;
    l_elem_t *first;
    void(*del)(void *);
} l_list_t;


typedef struct dn_collision_sprites dn_coll_sprites_t;

typedef struct dn_texture_t_container {
    char *id;
    sfTexture *texture;
    size_t x_tiles;
    size_t y_tiles;
} dn_texture_t;
typedef struct dn_scene_t_container {
    l_list_t *sprites;
    l_list_t *textures;
    sfMusic *music;
    sfFont *font;
    size_t id_sprite;
    char *id;
    void *creation;
} dn_scene_t;
typedef struct dn_window_t_container {
    sfRenderWindow *window;
    sfClock *clock;
    dn_scene_t *scene;
    l_list_t *scenes;
    sfVector2i resolution;
    sfVector2i size;
    void(*manage_collision)(dn_coll_sprites_t *, struct dn_window_t_container *);
    bool to_be_closed;
} dn_window_t;
typedef struct dn_environment_info {
    float time_delta;
    dn_window_t *window;
    sfEvent *event;
}dn_envinfo_t;
typedef struct dn_sprite_t_display_info {
    int rotate_texture;
    int rotate_outline;
    int rotate_text;
    dn_texture_t *texture;
    sfIntRect rect;
    bool draw_texture;
    sfRectangleShape *outline;
    sfColor outline_color;
    sfVector2f outline_size;
    bool draw_outline;
    sfCircleShape *circle;
    sfColor circle_color;
    float circle_size;
    bool draw_circle;
    sfText *text;
    sfColor text_color;
    int text_size;
    bool draw_text;
} dn_display_info_t;
typedef struct dn_sprite_t_container {
    size_t id;
    sfSprite *sprite;
    float angle;
    sfVector2f position;
    sfVector2f offset;
    sfVector2f center;
    dn_display_info_t display;
    void(*tick)(struct dn_sprite_t_container *, dn_envinfo_t *);
    void(*event)(struct dn_sprite_t_container *, dn_envinfo_t *);
    void(*destroy_data)(void *);
    bool collision;
    void *data;
} dn_sprite_t;
struct dn_collision_sprites {
    size_t id1;
    size_t id2;
};

#endif
