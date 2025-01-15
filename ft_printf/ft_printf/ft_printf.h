/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:16:37 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 15:17:35 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_printstr(char *str);
int	ft_printint(int n);
int	ft_printunsigned(unsigned int u);
int	print_hexadecimal(unsigned int n, const char word);
int	ft_print_pointer(unsigned long long ptr);
int	ft_printf(const char *format, ...);

#endif
