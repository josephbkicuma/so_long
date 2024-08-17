/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:45:24 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/17 11:23:35 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    player_animation(t_mlx *var, int x, int y)
{
    static int  is_first_draw = 1;
    
    if (is_first_draw)
    {
        mlx_put_image_to_window(var->ptr, var->win, var->img_player, x, y);
        is_first_draw = 0;
    }
    if (var->key == RIGHT)
        mlx_put_image_to_window(var->ptr, var->win, var->p_right, x, y);
    else if (var->key == LEFT)
        mlx_put_image_to_window(var->ptr, var->win, var->p_left, x, y);
    else if (var->key == UP)
        mlx_put_image_to_window(var->ptr, var->win, var->p_back, x, y);
    else if (var->key == DOWN)
        mlx_put_image_to_window(var->ptr, var->win, var->img_player, x, y);
    else
        mlx_put_image_to_window(var->ptr, var->win, var->img_player, x, y);
}
