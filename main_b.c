/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriah <badriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:39:34 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 09:08:44 by badriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_solong *game)
{
	game->x = 0;
	game->y = 0;
	game->p = 0;
	game->u = 0;
	game->e = 0;
	game->w = 0;
	game->f = 0;
	game->count_p = 0;
}

void	split_work(t_solong *game, char *argv[])
{
	(void) argv;
	map_checker(game, argv);
	map_validator(game);
	img(game);
	put_img(game);
	mlx_key_hook(game->window, &ft_player, game);
	mlx_hook(game->window, 17, 1L << 17, cross, game);
	mlx_loop(game->mlx_ptr);
}

int	check_ext(char **argv)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	i = i - 4;
	if (argv[1][i] == '.' && argv[1][i + 1] == 'b' \
		&& argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r')
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (argc == 2)
	{
		if (check_ext(argv) == 0)
			split_work(&game, argv);
		else
		{
			ft_printf(BRED"Not a right extension\n");
			exit(0);
		}
	}
	else
		exit(0);
}
