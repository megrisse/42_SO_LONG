/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:02:13 by megrisse          #+#    #+#             */
/*   Updated: 2021/11/25 14:11:04 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			x;

	ptr = (unsigned char *) b;
	x = 0;
	while (x < len)
	{
		ptr[x] = (unsigned char) c;
		x++;
	}
	return ((void *)ptr);
}
