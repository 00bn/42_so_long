/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:28 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/01 15:39:50 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || c == '\0')
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		stri;
	int		j;
	char	*strcpy;

	stri = 0;
	while (str[stri] != '\0' && str[stri] != '\n')
		stri++;
	if (str[stri] == '\0')
	{
		free(str);
		return (NULL);
	}
	strcpy = (char *)malloc(sizeof(char) * (ft_strlen(str) - stri + 1));
	if (!strcpy)
		return (NULL);
	stri++;
	j = 0;
	while (str[stri] != '\0')
		strcpy[j++] = str[stri++];
	strcpy[j] = '\0';
	free(str);
	return (strcpy);
}
