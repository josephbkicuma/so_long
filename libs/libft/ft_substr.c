/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:56:56 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/13 16:56:58 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (((slen - start) > len) && (start < slen))
		sub = malloc((len * sizeof(char) + 1));
	else if (start > slen)
		sub = malloc(sizeof(char));
	else
		sub = malloc(((slen - start) * sizeof(char) + 1));
	if (!sub)
		return (NULL);
	if ((start < slen))
	{
		while ((i < len) && s[start])
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
