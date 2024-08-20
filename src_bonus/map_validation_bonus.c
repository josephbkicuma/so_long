/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:25:35 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/20 10:54:04 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	validate_map_extension(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < 4 || len2 < 4)
		return (0);
	return (ft_strncmp(s1 + len1 - 4, s2 + len2 - 4, 4) == 0);
}

int	validate_map_alignment(char **map)
{
	size_t	i;
	size_t	lign;

	lign = (size_t)ft_strlen_n(map[0]);
	i = -1;
	while (map[++i])
		if (lign != (size_t)ft_strlen_n(map[i]))
			return (0);
	return (1);
}

int	validate_map_wall(char **map, size_t width, size_t heigh)
{
	size_t	i;

	width--;
	heigh--;
	i = -1;
	while (++i <= width)
		if (map[0][i] != '1')
			return (0);
	i = -1;
	while (++i <= width)
		if (map[heigh][i] != '1')
			return (0);
	i = -1;
	while (++i <= heigh)
		if (map[i][0] != '1')
			return (0);
	i = -1;
	while (++i <= heigh)
		if (map[i][width] != '1')
			return (0);
	return (1);
}
