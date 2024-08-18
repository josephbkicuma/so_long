/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:14:06 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/18 13:59:56 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(t_mlx *tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab->map[cur.y][cur.x] != 'P' && tab->map[cur.y][cur.x] != 'C'
			&& tab->map[cur.y][cur.x] != '0' && tab->map[cur.y][cur.x] != 'E'))
		return ;
	if (tab->map[cur.y][cur.x] == 'C')
		tab->map[cur.y][cur.x] = 'L';
	if (tab->map[cur.y][cur.x] == '0')
		tab->map[cur.y][cur.x] = 'Z';
	if (tab->map[cur.y][cur.x] == 'P')
		tab->map[cur.y][cur.x] = 'J';
	if (tab->map[cur.y][cur.x] == 'E')
		tab->map[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	fill_reverse(t_mlx *tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab->map[cur.y][cur.x] != 'J' && tab->map[cur.y][cur.x] != 'L'
			&& tab->map[cur.y][cur.x] != 'Z' && tab->map[cur.y][cur.x] != 'X'))
		return ;
	if (tab->map[cur.y][cur.x] == 'L')
		tab->map[cur.y][cur.x] = 'C';
	if (tab->map[cur.y][cur.x] == 'Z')
		tab->map[cur.y][cur.x] = '0';
	if (tab->map[cur.y][cur.x] == 'J')
		tab->map[cur.y][cur.x] = 'P';
	if (tab->map[cur.y][cur.x] == 'X')
		tab->map[cur.y][cur.x] = 'E';
	fill_reverse(tab, size, (t_point){cur.x - 1, cur.y});
	fill_reverse(tab, size, (t_point){cur.x + 1, cur.y});
	fill_reverse(tab, size, (t_point){cur.x, cur.y - 1});
	fill_reverse(tab, size, (t_point){cur.x, cur.y + 1});
}

void	fill_exit(t_mlx *tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab->map[cur.y][cur.x] != 'P' && tab->map[cur.y][cur.x] != 'C'
			&& tab->map[cur.y][cur.x] != '0'))
		return ;
	if (tab->map[cur.y][cur.x] == 'C')
		tab->map[cur.y][cur.x] = 'L';
	if (tab->map[cur.y][cur.x] == '0')
		tab->map[cur.y][cur.x] = 'Z';
	if (tab->map[cur.y][cur.x] == 'P')
		tab->map[cur.y][cur.x] = 'J';
	fill_exit(tab, size, (t_point){cur.x - 1, cur.y});
	fill_exit(tab, size, (t_point){cur.x + 1, cur.y});
	fill_exit(tab, size, (t_point){cur.x, cur.y - 1});
	fill_exit(tab, size, (t_point){cur.x, cur.y + 1});
}

int	valid_access(t_mlx *var, t_point size)
{
	t_point	begin;
	size_t	pos[2];
	t_mlx	*ptr;

	verify_char_in_position(var->map, pos, 'P');
	begin.x = pos[1];
	begin.y = pos[0];
	ptr = var;
	fill(var, size, begin);
	if (count_elements(var->map, 'C') > 0 || count_elements(var->map, 'E') > 0)
		return (0);
	fill_reverse(var, size, begin);
	fill_exit(ptr, size, begin);
	if (count_elements(var->map, 'C') > 0)
		return (0);
	fill_reverse(var, size, begin);
	return (1);
}
