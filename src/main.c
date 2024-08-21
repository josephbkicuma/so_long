/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:30:39 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/20 11:58:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	last_line(char **map);

int	key_handler(int key, void *param)
{
	t_mlx	*var;

	var = (t_mlx *)param;
	if (key == KEY_ESC)
		free_all(var);
	player_mov(key, var);
	return (0);
}

void	import_images(t_mlx *var)
{
	int	i;

	i = PIXELS;
	var->img_wall = mlx_xpm_file_to_image(var->ptr, "./resources/wall.xpm", &i,
			&i);
	var->img_player = mlx_xpm_file_to_image(var->ptr, "./resources/player.xpm",
			&i, &i);
	var->img_exit = mlx_xpm_file_to_image(var->ptr, "./resources/exit.xpm", &i,
			&i);
	var->img_col = mlx_xpm_file_to_image(var->ptr, "./resources/col.xpm", &i,
			&i);
	var->img_bg = mlx_xpm_file_to_image(var->ptr, "./resources/bg.xpm", &i, &i);
}

int	validate(t_mlx *var, char *map_path)
{
	t_point	size;

	var->map = draw_map(map_path);
	var->width = map_width(map_path);
	var->heigh = map_heigh(map_path);
	size.x = var->width / PIXELS;
	size.y = var->heigh / PIXELS;
	if (!verify_num_elements(var->map) || !verify_inavlids_elements(var->map)
		|| (var->heigh == var->width) || (var->heigh <= 2 || var->width <= 2)
		|| !validate_map_extension(".ber", map_path)
		|| !validate_map_alignment(var->map) || !validate_map_wall(var->map,
			(var->width / PIXELS), (var->heigh / PIXELS)) || !valid_access(var,
			size) || !last_line(var->map))
	{
		ft_putstr("Error: Invalid Map\n");
		free_map(var->map);
		return (0);
	}
	return (1);
}

static int	last_line(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
		;
	i--;
	j = -1;
	while (map[i][++j])
		if (map[i][j] == '\n')
			return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_mlx	var;

	if (ac != 2)
		return (ft_putstr("Error: Invalid Params\n"));
	if (!validate(&var, av[1]))
		return (EXIT_FAILURE);
	var.ptr = mlx_init();
	if (!var.ptr)
	{
		perror("mlx_init");
		return (EXIT_FAILURE);
	}
	var.key = 0;
	var.win = mlx_new_window(var.ptr, var.width, var.heigh, "so_long");
	import_images(&var);
	mlx_hook(var.win, 17, 0, free_all, &var);
	draw_assets_on_map(&var);
	mlx_key_hook(var.win, key_handler, &var);
	mlx_loop(var.ptr);
	return (0);
}
