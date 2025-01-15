/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:19:07 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 15:19:39 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_hexadecimal(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	search_hexadecimal(unsigned int n, const char word)
{
	if (n >= 16)
	{
		search_hexadecimal(n / 16, word);
		search_hexadecimal(n % 16, word);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (word == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	print_hexadecimal(unsigned int n, const char word)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
		search_hexadecimal(n, word);
	return (lenght_hexadecimal(n));
}
