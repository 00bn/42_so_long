/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:24:44 by balnahdi          #+#    #+#             */
/*   Updated: 2021/11/28 18:53:11 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_put_ptr_num(unsigned long long n)
{
	if (n > 15)
	{
		ft_put_ptr_num(n / 16);
		ft_put_ptr_num(n % 16);
	}
	if (n <= 15)
	{
		if (n < 10)
			ft_putchar_fd(n + '0');
		else
			ft_putchar_fd(n - 10 + 'a' );
	}
}

int	printptr(unsigned long long ptr)
{
	unsigned long long	l;

	l = ptr;
	ft_putstr("0x");
	if (ptr == 0)
		ft_putchar_fd('0');
	else
		ft_put_ptr_num(ptr);
	return (2 + len_ptr_num(l));
}

unsigned long long	len_ptr_num(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i ++;
	}
	return (i);
}
