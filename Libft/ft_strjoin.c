/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:12:14 by megrisse          #+#    #+#             */
/*   Updated: 2021/11/19 01:04:00 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	x;
	size_t	y;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	x = -1;
	y = -1;
	if (p == NULL)
		return (NULL);
	while (s1[++x])
		p[x] = s1[x];
	while (s2[++y])
		p[x + y] = s2[y];
	p[x + y] = '\0';
	return (p);
}
