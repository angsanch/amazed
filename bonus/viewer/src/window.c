/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** window
*/
#include "../../../include/viewer.h"

void events(window_t *info)
{
    while (sfRenderWindow_pollEvent(info->window, &info->event)) {
        if (info->event.type == sfEvtClosed)
            sfRenderWindow_close(info->window);
    }
}

void destroy(window_t *w, tunnel_t **tunnel, bot_t **bot, roomv_t **room)
{
    for (tunnel_t *tw = *tunnel; tw != NULL; tw = tw->next)
        sfShape_destroy(tw->line);
    for (bot_t *pl = *bot; pl != NULL; pl = pl->next)
        sfSprite_destroy(pl->spr_bot);
    sfTexture_destroy(w->tx_bot);
    for (roomv_t *r = *room; r != NULL; r = r->next)
        sfSprite_destroy(r->spr_room);
    sfRenderWindow_destroy(w->window);
}

void displaystuff(tunnel_t **tunnel, bot_t **bot, window_t *w, roomv_t **room)
{
    for (tunnel_t *t = *tunnel; t != NULL; t = t->next){
        sfSprite_setPosition(t->spr_tunnel, t->t_pos);
        sfRenderWindow_drawSprite(w->window, t->spr_tunnel, NULL);
    }
    for (bot_t *b = *bot; b != NULL; b = b->next){
        //movement(b); MAKE MOVEMENT FUNCTION TO MOVE THE BOTS
        sfRenderWindow_drawSprite(w->window, b->spr_bot, NULL);
    }
    for (roomv_t *r = *room; r != NULL; r = r->next){
        sfSprite_setPosition(r->spr_room, r->r_pos);
        sfRenderWindow_drawSprite(w->window, r->spr_room, NULL);
    }
}

int window(window_t *window, tunnel_t **tunnel, bot_t **bot, roomv_t **room)
{
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        sfClock_restart(clock);
        // sfSprite_setTexture(window->spr_background, window->tx_background, sfTrue);
        events(window);
        sfRenderWindow_clear(window->window, sfTransparent);
        // sfRenderWindow_drawSprite(window->window, window->spr_background, NULL);
        displaystuff(tunnel, bot, window, room);
        sfRenderWindow_display(window->window);
    }
    destroy(window, tunnel, bot, room);
    return (0);
}
