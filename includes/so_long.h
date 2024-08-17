/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:09:08 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/17 10:31:37 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <stdio.h>

# define PIXELS 50
# define KEY_ESC 65307
# define UP 119
# define DOWN 115
# define D 115
# define L 97
# define LEFT 97
# define RIGHT 100

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img_bg;
	void	*img_wall;
	void	*img_col;
	void	*img_exit;
	void	*img_player;
	void	*img_count;
	char	**map;
	size_t	width;
	size_t	heigh;
}			t_mlx;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

size_t		map_width(char *map_path);
size_t		map_heigh(char *map_path);
int			free_all(t_mlx *mlx);
char		**draw_map(char *map_path);
void		draw_assets_on_map(t_mlx *var);
void		free_map(char **map);
void		player_mov(int key, t_mlx *var);
int			verify_num_elements(char **map);
int			verify_inavlids_elements(char **map);
int			validate_map_extension(const char *s1, const char *s2);
int			validate_map_alignment(char **map);
int			validate_map_wall(char **map, size_t width, size_t heigh);
int			verify_char_in_position(char **map, size_t *pos, char c);
int			valid_access(t_mlx *var, t_point size);
int			count_elements(char **map, char c);

#endif