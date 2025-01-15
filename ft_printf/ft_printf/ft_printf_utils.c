/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:20:30 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 15:22:03 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

int	ft_printint(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		if (n == -2147483648)
		{
			ft_putchar('2');
			count++;
			n = 147483648;
		}
		else
			n = -n;
	}
	if (n > 9)
		count += ft_printint(n / 10);
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}

int	ft_printunsigned(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_printunsigned(u / 10);
	ft_putchar((u % 10) + '0');
	count++;
	return (count);
}
