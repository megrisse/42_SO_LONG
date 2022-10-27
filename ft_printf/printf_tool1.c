/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tool1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:03:29 by megrisse          #+#    #+#             */
/*   Updated: 2021/12/06 08:23:23 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, const char *base, int *len)
{
	if (n < 16)
		ft_putchar(base[n], len);
	else
	{
		ft_puthex(n / 16, base, len);
		ft_putchar(base[n % 16], len);
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, len);
		ft_putchar((n % 10) + '0', len);
	}
	else
		ft_putchar(n + '0', len);
}

void	ft_putnbr(int c, int *len)
{
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
			*len = *len + 11;
		return ;
	}
	else if (c < 0)
	{
		ft_putchar('-', len);
		c *= -1;
	}
	if (c >= 0 && c < 10)
		ft_putchar(c + '0', len);
	else
	{
		ft_putnbr(c / 10, len);
		ft_putchar((c % 10) + '0', len);
	}	
}
