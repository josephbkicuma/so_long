/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:08:31 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/17 10:58:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

static void	free_player_img(t_mlx *var)
{
	if (var->p_back)
		mlx_destroy_image(var->ptr, var->p_back);
	if (var->p_right)
		mlx_destroy_image(var->ptr, var->p_right);
	if (var->p_left)
		mlx_destroy_image(var->ptr, var->p_left);
	if (var->img_player)
		mlx_destroy_image(var->ptr, var->img_player);
}

int	free_all(t_mlx *var)
{
	if (var)
	{
		if (var->win)
			mlx_destroy_window(var->ptr, var->win);
		if (var->img_wall)
			mlx_destroy_image(var->ptr, var->img_wall);
		if (var->img_col)
			mlx_destroy_image(var->ptr, var->img_col);
		if (var->img_exit)
			mlx_destroy_image(var->ptr, var->img_exit);
		if (var->img_bg)
			mlx_destroy_image(var->ptr, var->img_bg);
		if (var->img_count)
			mlx_destroy_image(var->ptr, var->img_count);
		free_player_img(var);
		if (var->ptr)
		{
			mlx_destroy_display(var->ptr);
			free(var->ptr);
		}
		if (var->map)
			free_map(var->map);
	}
	exit(EXIT_SUCCESS);
}
