/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:43:09 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:25:40 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_shape(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->y && game->maparr[j])
	{
		i = 0;
		while (game->maparr[j][i] != '\0')
		{
			if (game->maparr[j][i] == '\n')
			{
				if (i != (int)game->x || i == game->y)
				{
					ft_printf(BRED"Not a right map shape!\n");
					ft_free(game);
					ft_endmlx(game);
					exit(0);
					break ;
				}
			}
			i++;
		}
		j++;
	}
}

int	check_top_wall(t_solong *game)
{
	int	i;

	i = 0;
	while (game->maparr[0][i] != '\n' && game->maparr[0][i] == '1' )
		i++;
	if (i == (int)game->x)
		return (0);
	else
		return (1);
}

int	check_bottmo_wall(t_solong *game)
{
	int	i;

	i = 0;
	while (game->maparr[game->y - 1][i] != '\0' \
		&& game->maparr[game->y - 1][i] == '1')
		i++;
	if (i == (int)game->x)
		return (0);
	else
		return (1);
}

void	check_wall_side(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->y)
	{
		if ((game->maparr[j][0] != '1' || \
		game->maparr[j][(int)game->x - 1] != '1') && j != (int)game->x)
		{
			ft_printf(BRED"Check side walls\n");
			ft_free(game);
			ft_endmlx(game);
			exit(0);
		}
		j++;
	}
}

void	map_validator(t_solong *game)
{
	check_elem(game);
	if (check_top_wall(game) != 0)
	{
		ft_printf(BRED"Chekc top and bottom walls\n");
		ft_free(game);
		ft_endmlx(game);
		exit(0);
	}
	if (check_bottmo_wall(game) != 0)
	{
		ft_printf(BRED"Check top and bottom map walls\n");
		ft_free(game);
		ft_endmlx(game);
		exit(0);
	}
	check_shape(game);
	check_wall_side(game);
	check_elem_num(game);
	if (game->p < 1 || game->u != 1 || game->e < 1 || game->f < 1)
	{
		ft_printf(BRED"Check # of elements that map require\n");
		ft_free(game);
		ft_endmlx(game);
		exit(0);
	}
}
