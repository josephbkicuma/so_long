/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:08:31 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/15 13:36:57 by jquicuma         ###   ########.fr       */
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
		if (var->img_player)
			mlx_destroy_image(var->ptr, var->img_player);
		if (var->img_exit)
			mlx_destroy_image(var->ptr, var->img_exit);
		if (var->img_bg)
			mlx_destroy_image(var->ptr, var->img_bg);
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
