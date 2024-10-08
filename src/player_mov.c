/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:48:22 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/23 11:32:19 by jquicuma         ###   ########.fr       */
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

int	player_mov(int key, t_mlx *var)
{
	static int	i = 0;
	int			is_the_same;
	size_t		pos[2];
	char		*num;

	is_the_same = i;
	verify_char_in_position(var->map, pos, 'P');
	var->mov = i;
	i += check(var, key, pos);
	var->key = key;
	draw_assets_on_map(var);
	num = ft_itoa(i);
	if (is_the_same != i)
	{
		ft_putstr(num);
		ft_putstr("\n");
	}
	free(num);
	return (i);
}

static int	is_valid_position(char c, t_mlx *var)
{
	char	*num_mov;
	
	if (c == '0')
		return (1);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (1);
	else if (c == 'E' && (!verify_colet(var->map)))
	{
		num_mov = ft_itoa(var->mov + 1);
		ft_putstr(num_mov);
		ft_putstr("\n");
		free(num_mov);
		free_all(var);
	}
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
