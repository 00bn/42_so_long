/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:32:53 by balnahdi          #+#    #+#             */
/*   Updated: 2021/11/28 19:33:33 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

unsigned long long	len_ptr_num(unsigned long long n);
int					ft_printf(const char *str, ...);
int					format(char str, va_list arg);
int					ft_putchar_fd(char s);
int					ft_putstr(char const *s);
int					ft_putnbr_fd(int n);
int					ft_putnbr_unsigend(unsigned int n);
int					ft_put_hex_num( unsigned int n, char str);
void				ft_put_ptr_num(unsigned long long n);
int					printptr(unsigned long long ptr);
int					len_num(int n);
int					len_un_num(unsigned int n);
int					len_unhex_num(unsigned int n);

#endif
