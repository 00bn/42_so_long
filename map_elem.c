/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriah <badriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:41:39 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 07:55:03 by badriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elem(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->y && game->maparr[j])
	{
		i = 0;
		while (game->maparr[j][i] != '\0')
		{
			if (game->maparr[j][i] == '\n' || game->maparr[j][i] == 'C' || \
				game->maparr[j][i] == 'P' || game->maparr[j][i] == 'E' || \
				game->maparr[j][i] == '1' || game->maparr[j][i] == '0')
				i++;
			else
			{
				ft_printf(BRED"Check type of map elements\n");
				ft_free(game);
				ft_endmlx(game);
				exit(0);
			}	
		}
		j++;
	}
}

void	check_elem_num(t_solong *game)
{
	int	j;
	int	i;

	j = 0;
	while (j < game->y && game->maparr[j])
	{
		i = 0;
		while (game->maparr[j][i] != '\0')
		{
			if (game->maparr[j][i] == 'C')
				game->p++;
			if (game->maparr[j][i] == 'P')
				game->u++;
			if (game->maparr[j][i] == 'E')
				game->e++;
			if (game->maparr[j][i] == '0')
				game->f++;
			i++;
		}
		j++;
	}
}
