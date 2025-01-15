/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:08 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 15:16:24 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char wd)
{
	int	size;

	size = 0;
	if (wd == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (wd == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (wd == 'p')
		size += ft_print_pointer(va_arg(args, unsigned long long));
	else if (wd == 'd' || wd == 'i')
		size += ft_printint(va_arg(args, int));
	else if (wd == 'u')
		size += ft_printunsigned(va_arg(args, unsigned int));
	else if (wd == 'x' || wd == 'X')
		size += print_hexadecimal(va_arg(args, unsigned int), wd);
	else if (wd == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			i++;
			size += ft_format(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
