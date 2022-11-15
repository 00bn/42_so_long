/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:03:45 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 06:30:50 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
