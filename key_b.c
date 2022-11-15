/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:26:14 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:54:22 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_mov(t_solong *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->w_img, 0, 0);
	mlx_string_put(game->mlx_ptr, game->window, 20, 35, 0x703B3B, \
	 ft_itoa(game->count_p));
}

void	c_and_e(t_solong *game)
{
	int	x;
	int	y;

	x = game->player_next_pos.x / 64;
	y = game->player_next_pos.y / 64;
	if (game->maparr[y][x] == 'C')
	{
		game->maparr[y][x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->p_img, \
			game->player_next_pos.x, game->player_next_pos.y);
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->f_img, \
			game->player_pos.x, game->player_pos.y);
		game->player_pos.x = game->player_next_pos.x;
		game->player_pos.y = game->player_next_pos.y;
		game->p--;
	}
	if (game->maparr[y][x] == 'E' && game->p == 0)
	{
		ft_printf(BBLU"YOU WIN!\n");
		ft_free(game);
		ft_endmlx(game);
		exit(0);
	}
}

void	action(t_solong *game)
{
	int	x;
	int	y;

	x = game->player_next_pos.x / 64;
	y = game->player_next_pos.y / 64;
	if (game->maparr[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->p_img, \
			game->player_next_pos.x, game->player_next_pos.y);
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->f_img, \
			game->player_pos.x, game->player_pos.y);
		game->player_pos.x = game->player_next_pos.x;
		game->player_pos.y = game->player_next_pos.y;
	}
	if (game->maparr[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->p_img, \
			game->player_next_pos.x, game->player_next_pos.y);
		mlx_put_image_to_window(game->mlx_ptr, game->window, game->f_img, \
			game->player_pos.x, game->player_pos.y);
		game->player_pos.x = game->player_next_pos.x;
		game->player_pos.y = game->player_next_pos.y;
	}
	c_and_e(game);
}

int	ft_player(int key, void *game2)
{	
	t_solong	*game;

	game = (t_solong *)game2;
	game->player_next_pos.x = game->player_pos.x;
	game->player_next_pos.y = game->player_pos.y;
	if (key == D)
		game->player_next_pos.x += 64;
	else if (key == A)
		game->player_next_pos.x -= 64;
	else if (key == W)
		game->player_next_pos.y += 64;
	else if (key == S)
		game->player_next_pos.y -= 64;
	else if (key == ESC)
	{
		cross(game);
		exit(0);
	}
	else
		return (1);
	action(game);
	put_mov(game);
	game->count_p++;
	return (0);
}
