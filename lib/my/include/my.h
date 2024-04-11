/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "structs.h"
    #include "macros.h"


char *convert_base(char const *nbr,
    char const *base_from, char const *base_to);
char *get_next_line(int fd);
void *my_calloc(size_t count, size_t size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_intlen_base(int nb, int base_len);
int my_getnbr_base(char const *str, char const *base);
int my_intlen(int nb);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
int my_memcmp(const void *s1, const void *s2, size_t n);
int my_memchr_index(const void *m, int c, int len);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memjoin(const void *m1, size_t s1, const void *m2, size_t s2);
void *my_memmove(void *dst, const void *src, size_t n);
void *my_memset(void *b, int c, size_t len);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
void my_put_nbr(int nb);
size_t my_putstr(char const *str);
void swap_chr(char *a, char *b);
void my_revmem(void *str, size_t size);
char *my_revstr(char *str);
void my_showmem(char const *str, size_t size);
void my_showstr(char const *str);
void my_show_word_array(char *const *tab);
void my_sort_int_array(int *array, size_t size);
char **free_string_array(char **result);
size_t get_pointer_array_len(void *arr_in);
char **my_split(char const *s, char c);
char **my_coolersplit(char const *s, char const *separators);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
ssize_t my_strchr_index(char const *str, char c);
size_t my_strchr_count(char const *str, char c);
char *my_strchr(char const *str, char c);
char *my_strrchr(char const *str, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strjoin(char *s1, char *s2);
char *my_coolerstrjoin(size_t n, ...);
int my_isalpha(char c);
int my_str_isalpha(char const *str);
int my_islower(char c);
int my_str_islower(char const *str);
int my_isnumeric(char c);
int my_str_isnum(char const *str);
int my_isprintable(char c);
int my_str_isprintable(char const *str);
int my_isupper(char c);
int my_str_isupper(char const *stri);
int my_isalnum(char c);
int my_str_isalnum(char const *str);
size_t my_strlen(char const *str);
void my_to_lower(char *chr);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, size_t nb);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncpy(char *dest, char const *src, size_t n);
char *my_strreplace(char *base, char *key, char *replace);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
void my_to_upper(char *chr);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int report_error(char *str, int response);

int my_printf(char const *format, ...);
int my_sprintf(char *str, char const *format, ...);
int my_dprintf(int fd, char const *format, ...);
int my_sbufferf(char **str, char const *format, ...);

void list_delete(l_list_t *l);
l_list_t *list_destroy(l_list_t *l);
void list_initialize(l_list_t *l, void(*del)(void *));
l_list_t *list_create(void(*del)(void *));
size_t list_len(l_list_t *l);
int list_push(l_list_t *l, void *content);
int list_append(l_list_t *l, void *content);
int list_insert(l_list_t *l, size_t index, void *content);
int list_pop(l_list_t *l, size_t index);
void *list_get_index(l_list_t *l, size_t index);
void list_import(l_list_t *l, void **data);
void **list_export(l_list_t *l, void *(*transform)(void *));
void list_unlink(l_list_t *l);
void list_pop_first(l_list_t *l);
void list_iter(l_list_t *l, void(*func)(void *, void *), void *data);
ssize_t list_first_fulfil(l_list_t *l, int(*func)(void *, void *), void *data);
size_t list_count_fulfil(l_list_t *l, int(*func)(void *, void *), void *data);
int list_sort(l_list_t *l, int(*comp)(void *, void *));

dn_texture_t *search_texture(dn_scene_t *scene, char *id);
dn_sprite_t *search_sprite(dn_scene_t *scene, size_t id);
int focus_scene(dn_window_t *window, char *id);
dn_scene_t *create_scene(char const *id);
void add_sprite(dn_scene_t *scene, float x, float y);
void add_sprite_set_graphics(dn_scene_t *scene, char *texture_id,
    void(*config)(dn_sprite_t *));
void add_sprite_set_functions(dn_scene_t *scene,
    void(*tick)(struct dn_sprite_t_container *, dn_envinfo_t *),
    void(*event)(struct dn_sprite_t_container *, dn_envinfo_t *));
void add_sprite_set_text(dn_scene_t *scene, char *text);
void add_sprite_set_text_style(dn_scene_t *scene, sfColor color, size_t size);
void sprite_set_text(dn_sprite_t *sprite, char *str);
void add_push_sprite(dn_scene_t *scene);
void add_sprite_set_data(dn_scene_t *scene, void *data,
    void(*destroy_data)(void *));
void create_button(dn_scene_t *scene, char *text, sfVector2f pos);
void sprite_link_texture(dn_sprite_t *sprite, dn_texture_t *texture);
void sprite_add_data(dn_sprite_t *sprite, void *data,
    void(*destroy_data)(void *));
void sprite_set_rect(dn_sprite_t *sprite, size_t x, size_t y);
int is_on_sprite(dn_window_t *window, dn_sprite_t *sprite, int x, int y);
dn_texture_t *create_texture(dn_scene_t *scene, char const *path,
    size_t x_tiles, size_t y_tiles);
dn_sprite_t *create_sprite(dn_scene_t *scene);
int delete_sprite_by_id(dn_scene_t *scene, size_t id);
dn_window_t *create_window(int width, int height, char *name, sfUint32 style);
void destroy_window(dn_window_t *window);
int tick_window(dn_window_t *window);
void display_sprite(void *sprite_void, void *window_void);
void limit_fps(dn_window_t *window, unsigned int limit);
void window_collisions(dn_window_t *window,
    void (*manage)(dn_coll_sprites_t *, dn_window_t *));

#endif
