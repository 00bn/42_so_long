/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:12:49 by balnahdi          #+#    #+#             */
/*   Updated: 2022/04/06 10:50:03 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define PP 64
# define D 2
# define A 0
# define W 1
# define S 13
# define ESC 53
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*window;
	int		y;
	size_t	x;
	char	**maparr;
	int		f;
	int		p;
	int		u;
	int		e;
	int		w;
	int		count_p;
	void	*p_img;
	void	*f_img;
	void	*c_img;
	void	*e_img;
	void	*w_img;
	char	*p_path;
	char	*f_path;
	char	*w_path;
	char	*e_path;
	char	*c_path;
	t_axis	player_pos;
	t_axis	player_next_pos;
}	t_solong;

char	**map_checker(t_solong *game, char **argv);
void	map_validator(t_solong *game);
void	check_elem(t_solong *game);
void	check_elem_num(t_solong *game);
int		ft_player(int key, void *game);

//img
void	put_img(t_solong *game);
void	put_img_elem(t_solong *game, int x, int y);
void	img(t_solong *game);

//lib-utils
char	*ft_itoa(int n);

//free
void	endgame(t_solong *game);
void	ft_free(t_solong *game);
void	ft_endmlx(t_solong *game);
int		cross(t_solong *game);
#endif