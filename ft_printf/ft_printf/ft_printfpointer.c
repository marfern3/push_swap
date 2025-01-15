/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:19:50 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 15:20:14 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenght_pointer(unsigned long long ptr)
{
	int	lenght;

	lenght = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		lenght++;
	}
	return (lenght);
}

static void	search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		search_pointer(ptr / 16);
		search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	size += ft_printstr("0x");
	if (ptr == 0)
		size += ft_putchar('0');
	else
	{
		search_pointer(ptr);
		size += ft_lenght_pointer(ptr);
	}
	return (size);
}
