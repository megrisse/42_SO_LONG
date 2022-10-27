/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:09:06 by megrisse          #+#    #+#             */
/*   Updated: 2021/12/08 22:24:05 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include <stdarg.h>

static void	ft_check_printf(const char *str, va_list args, int i, int *len)
{
	i++;
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int), len);
	if (str[i] == '%')
		ft_putchar('%', len);
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *), len);
	if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr(va_arg(args, int), len);
	if (str[i] == 'x')
		ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", len);
	if (str[i] == 'X')
		ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	if (str[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	if (str[i] == 'p')
	{
		ft_putstr("0x", len);
		ft_put_adress(va_arg(args, unsigned long), "0123456789abcdef", len);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &len);
		else
		{
			ft_check_printf(str, args, i, &len);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}