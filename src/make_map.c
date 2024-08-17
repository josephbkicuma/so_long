/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:18:15 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/17 11:16:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_char(char map_char, t_mlx *var, size_t w, size_t h)
{
	mlx_put_image_to_window(var->ptr, var->win, var->img_bg, w * 50, h * 50);
	if (map_char == '1')
		mlx_put_image_to_window(var->ptr, var->win, var->img_wall, w * 50, h
			* 50);
	if (map_char == 'C')
		mlx_put_image_to_window(var->ptr, var->win, var->img_col, w * 50, h
			* 50);
	if (map_char == 'E')
		mlx_put_image_to_window(var->ptr, var->win, var->img_exit, w * 50, h
			* 50);
	if (map_char == 'P')
		player_animation(var, w * 50, h * 50);
	mlx_put_image_to_window(var->ptr, var->win, var->img_count, 0, 0);
}

size_t	map_width(char *map_path)
{
	int		fd;
	char	*line;
	size_t	width;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	width = 0;
	while (line[width])
		width++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ((width - 1) * PIXELS);
}

size_t	map_heigh(char *map_path)
{
	int		fd;
	char	*line;
	size_t	heigh;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	heigh = 0;
	while (line)
	{
		heigh++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (heigh * PIXELS);
}

char	**draw_map(char *map_path)
{
	int		fd;
	char	*line;
	char	**map;
	size_t	heigh;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(char *) * ((map_heigh(map_path) / PIXELS) + 1));
	if (!map)
		perror("malloc");
	line = get_next_line(fd);
	heigh = 0;
	while (line)
	{
		map[heigh++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[heigh] = NULL;
	close(fd);
	return (map);
}

void	draw_assets_on_map(t_mlx *var)
{
	size_t	h;
	size_t	w;

	h = 0;
	while (h < (var->heigh / PIXELS))
	{
		w = 0;
		while (w < (var->width / PIXELS))
		{
			verify_char(var->map[h][w], var, w, h);
			w++;
		}
		h++;
	}
}
