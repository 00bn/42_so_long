/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:25:43 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/04 20:25:52 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line(char *rdline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!rdline[i])
		return (NULL);
	while (rdline[i] != '\n' && rdline[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rdline[i] != '\0' && rdline[i] != '\n')
	{
		str[j++] = rdline[i++];
	}
	if (rdline[i] == '\n')
	{
		str[j++] = rdline[i++];
	}
	str[j] = '\0';
	return (str);
}

static char	*readtext(int fd, char *rdline)
{
	int		rdreturn;
	char	*buffer;

	buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buffer)
		return (NULL);
	rdreturn = 1;
	while (!ft_strchr(rdline, '\n') && rdreturn != 0)
	{
		rdreturn = read(fd, buffer, BUFFER_SIZE);
		if (rdreturn == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rdreturn] = '\0';
		if (!rdline)
		{
			rdline = (char *)malloc(sizeof(char));
			rdline[0] = '\0';
		}
		rdline = ft_strjoin(rdline, buffer);
	}
	free(buffer);
	return (rdline);
}

char	*get_next_line(int fd)
{
	char		*get_line;
	static char	*rdline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rdline = readtext(fd, rdline);
	if (!rdline)
		return (NULL);
	get_line = line(rdline);
	rdline = ft_strdup(rdline);
	return (get_line);
}
