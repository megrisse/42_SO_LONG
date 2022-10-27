/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:56:11 by megrisse          #+#    #+#             */
/*   Updated: 2021/11/24 16:48:24 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;
	size_t	x;

	x = 0;
	if (!s || len == 0)
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (start > s_len)
		start = s_len;
	if (start + len > s_len)
		len = s_len - start;
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s + start, len);
	p[len] = '\0';
	return (p);
}
