/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:03:45 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:49:12 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	absolute_value(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		len--;
		result[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

void	axis_finder(t_solong *game, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		endgame(game);
		exit(0);
	}
	while (get_next_line(fd))
	{
		i++;
		game->y = i;
	}
	close (fd);
}

char	**map_checker(t_solong *game, char **argv)
{
	char	*map;
	int		fd;
	int		i;

	axis_finder(game, argv);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		endgame(game);
		exit(0);
	}
	map = get_next_line(fd);
	game->x = ft_strlen(map);
	game->x--;
	game->maparr = (char **)malloc(sizeof(char *) * game->y);
	i = 0;
	while (map != NULL)
	{
		game->maparr[i] = (char *)malloc(sizeof(char) * ft_strlen(map) + 1);
		game->maparr[i++] = map;
		map = get_next_line(fd);
	}
	close(fd);
	return (game->maparr);
}
