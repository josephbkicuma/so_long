/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:48:22 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/20 10:54:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	int	new_x;
	int	new_y;

	new_x = pos[1];
	new_y = pos[0];
	if (key == RIGHT)
		new_x += 1;
	else if (key == LEFT)
		new_x -= 1;
	else if (key == UP)
		new_y -= 1;
	else if (key == DOWN)
		new_y += 1;
	if (is_valid_position(var->map[new_y][new_x], var))
	{
		var->map[new_y][new_x] = 'P';
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
	else if (c == 'N')
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
