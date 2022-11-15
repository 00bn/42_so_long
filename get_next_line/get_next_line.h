/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:56:20 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:56:23 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# define BUFFER_SIZE 100

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *str);
#endif
