/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:38:23 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:30:20 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_solong *game)
{
	int	x;

	x = 0;
	while (x < game->y)
	{
		free(game->maparr[x]);
		x++;
	}
	free(game->maparr);
}

void	endgame(t_solong *game)
{
	mlx_destroy_image(game->mlx_ptr, game->p_img);
	mlx_destroy_image(game->mlx_ptr, game->f_img);
	mlx_destroy_image(game->mlx_ptr, game->c_img);
	mlx_destroy_image(game->mlx_ptr, game->e_img);
	mlx_destroy_image(game->mlx_ptr, game->w_img);
	mlx_destroy_window(game->mlx_ptr, game->window);
}

void	ft_endmlx(t_solong *game)
{
	free(game->mlx_ptr);
}

int	cross(t_solong *game)
{
	ft_free(game);
	endgame(game);
	ft_endmlx(game);
	exit(0);
	return (0);
}
