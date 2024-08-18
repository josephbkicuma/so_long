/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:05:08 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/18 09:38:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				count++;
		}
	}
	return (count);
}

int	verify_num_elements(char **map)
{
	if (count_elements(map, 'P') != 1)
		return (0);
	else if (count_elements(map, 'E') != 1)
		return (0);
	else if (count_elements(map, 'C') < 1)
		return (0);
	return (1);
}

int	verify_inavlids_elements(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n'
				&& map[i][j] != 'N')
				return (0);
	}
	return (1);
}
