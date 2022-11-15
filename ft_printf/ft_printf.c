/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:59:19 by balnahdi          #+#    #+#             */
/*   Updated: 2021/11/28 17:43:40 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	format(char str, va_list arg)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar_fd(va_arg(arg, int));
	if (str == 's')
		len += ft_putstr(va_arg(arg, char *));
	if (str == 'd')
		len += ft_putnbr_fd(va_arg(arg, int));
	if (str == 'u')
		len += ft_putnbr_unsigend(va_arg(arg, unsigned int));
	if (str == 'i')
		len += ft_putnbr_fd(va_arg(arg, int));
	if (str == 'X' || str == 'x')
		len += ft_put_hex_num(va_arg(arg, unsigned int), str);
	if (str == 'p')
		len += printptr(va_arg(arg, unsigned long long));
	if (str == '%')
		len += ft_putchar_fd('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += format(str[i + 1], arg);
			i++;
		}
		else
		{
			len += ft_putchar_fd(str[i]);
		}
		i++;
	}
	return (len);
}
