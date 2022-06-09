/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhammani <yhammani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:27:39 by yhammani          #+#    #+#             */
/*   Updated: 2022/02/18 03:52:55 by yhammani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{	
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		str = "(null)";
	while (*str)
		write(1, str++, 1);
	return (0);
}

int	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (0);
}

int	ft_printf(char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 's')
			{
				if (format[i + 1] == 'd')
					ft_putnbr(va_arg(ap, int));
				if (format[i + 1] == 's')
					ft_putstr(va_arg(ap, char *));
				i++;
			}
			else
				ft_putchar(format[i]);
			i++;
		}
		write(1, &format[i++], 1);
	}
	va_end(ap);
	return (0);
}
