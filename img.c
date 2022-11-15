/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:26:07 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 06:30:41 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_solong *game)
{
	int			h;
	int			w;

	h = 64;
	w = 64;
	game->p_path = "./umaru.xpm";
	game->f_path = "./floor.xpm";
	game->w_path = "./wall.xpm";
	game->e_path = "./exit.xpm";
	game->c_path = "./pillow.xpm";
	game->window = mlx_new_window(game->mlx_ptr, \
		(64 * (int)game->x), (64 * game->y), "so_long");
	game->p_img = mlx_xpm_file_to_image \
		(game->mlx_ptr, game->p_path, &h, &w);
	game->f_img = mlx_xpm_file_to_image \
		(game->mlx_ptr, game->f_path, &h, &w);
	game->w_img = mlx_xpm_file_to_image \
		(game->mlx_ptr, game->w_path, &h, &w);
	game->e_img = mlx_xpm_file_to_image \
		(game->mlx_ptr, game->e_path, &h, &w);
	game->c_img = mlx_xpm_file_to_image \
		(game->mlx_ptr, game->c_path, &h, &w);
}

void	put_img_elem(t_solong *game, int x, int y)
{
	if (game->maparr[y][x] == 'P')
	{
		mlx_put_image_to_window (game->mlx_ptr, game->window, game->p_img, \
			 x * 64, y * 64);
		game->player_pos.x = x * 64;
		game->player_pos.y = y * 64;
	}	
	if (game->maparr[y][x] == '0')
		mlx_put_image_to_window (game->mlx_ptr, game->window, \
		 game->f_img, x * 64, y * 64);
	if (game->maparr[y][x] == '1')
		mlx_put_image_to_window (game->mlx_ptr, game->window, \
		game->w_img, x * 64, y * 64);
	if (game->maparr[y][x] == 'C')
		mlx_put_image_to_window (game->mlx_ptr, game->window, \
		 game->c_img, x * 64, y * 64);
	if (game->maparr[y][x] == 'E')
		mlx_put_image_to_window (game->mlx_ptr, game->window, \
			game->e_img, x * 64, y * 64);
}

void	put_img(t_solong *game)
{
	int			y;
	int			x;

	x = 0;
	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (game->maparr[y][x] != '\n' && game->maparr[y][x] != '\0')
		{
			put_img_elem(game, x, y);
			x++;
		}
		y++;
	}
}
