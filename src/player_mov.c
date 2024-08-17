/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:48:22 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/17 11:11:55 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_position(char c, t_mlx *var);

static int	verify_colet(char **map)
{
	size_t	heigh;
	size_t	width;

	heigh = -1;
	while (map[++heigh])
	{
		width = -1;
		while (map[heigh][++width])
			if (map[heigh][width] == 'C')
				return (1);
	}
	return (0);
}

static int	check(t_mlx *var, int key, size_t *pos)
{
	if (is_valid_position(var->map[pos[0]][pos[1] + 1], var) && key == RIGHT)
	{
		var->map[pos[0]][pos[1] + 1] = 'P';
		var->map[pos[0]][pos[1]] = '0';
		return (1);
	}
	else if (is_valid_position(var->map[pos[0]][pos[1] - 1], var) && key == L)
	{
		var->map[pos[0]][pos[1] - 1] = 'P';
		var->map[pos[0]][pos[1]] = '0';
		return (1);
	}
	else if (is_valid_position(var->map[pos[0] - 1][pos[1]], var) && key == UP)
	{
		var->map[pos[0] - 1][pos[1]] = 'P';
		var->map[pos[0]][pos[1]] = '0';
		return (1);
	}
	else if (is_valid_position(var->map[pos[0] + 1][pos[1]], var) && key == D)
	{
		var->map[pos[0] + 1][pos[1]] = 'P';
		var->map[pos[0]][pos[1]] = '0';
		return (1);
	}
	return (0);
}

void	player_mov(int key, t_mlx *var)
{
	static int	i = 0;
	size_t		pos[2];
	char		*num;

	verify_char_in_position(var->map, pos, 'P');
	i += check(var, key, pos);
	var->key = key;
	draw_assets_on_map(var);
	num = ft_itoa(i);
	mlx_string_put(var->ptr, var->win, 20, 30, 0xFFFFFF, num);
	free(num);
}

static int	is_valid_position(char c, t_mlx *var)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (1);
	else if (c == 'E' && (!verify_colet(var->map)))
		free_all(var);
	return (0);
}

int	verify_char_in_position(char **map, size_t *pos, char c)
{
	size_t	heigh;
	size_t	width;

	heigh = -1;
	while (map[++heigh])
	{
		width = -1;
		while (map[heigh][++width])
		{
			if (map[heigh][width] == c)
			{
				pos[0] = heigh;
				pos[1] = width;
				return (1);
			}
		}
	}
	return (0);
}
