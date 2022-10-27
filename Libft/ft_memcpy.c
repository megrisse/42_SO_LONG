/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:54:24 by megrisse          #+#    #+#             */
/*   Updated: 2021/11/26 00:06:45 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	char		*csrc;
	size_t		x;

	cdst = (char *) dst;
	csrc = (char *) src;
	x = 0;
	if (cdst == csrc)
		return (dst);
	if (!cdst && !src)
		return (0);
	while (n > x)
	{
		cdst[x] = csrc[x];
		x++;
	}
	return ((void *)cdst);
}
