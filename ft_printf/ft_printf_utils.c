/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:24:47 by balnahdi          #+#    #+#             */
/*   Updated: 2021/11/28 19:17:56 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar_fd(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr_fd(int n)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-');
		ft_putchar_fd(-(n % 10) + '0');
	}
	else
		ft_putchar_fd((n % 10) + '0');
	return (len_num(n));
}

int	ft_putnbr_unsigend(unsigned int n)
{
	int	a;

	a = n;
	if (n > 9)
		ft_putnbr_unsigend(n / 10);
	ft_putchar_fd((n % 10) + '0');
	return (len_un_num(a));
}

int	ft_put_hex_num(unsigned int n, char str)
{
	if (n > 15)
	{
		ft_put_hex_num(n / 16, str);
		ft_put_hex_num(n % 16, str);
	}
	if (n <= 15)
	{
		if (n < 10)
			ft_putchar_fd(n + '0');
		else if (n >= 10)
		{
			if (str == 'X')
				ft_putchar_fd(n - 10 + 'A' );
			if (str == 'x')
				ft_putchar_fd(n - 10 + 'a' );
		}
	}
	return (len_unhex_num(n));
}
