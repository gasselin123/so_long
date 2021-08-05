/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:23:00 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/15 15:15:35 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define RED	"\033[0;31m"
# define NC		"\033[0m"

typedef struct s_img {
	int		height;
	int		width;
	void	*coin;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*up;
	void	*left;
	void	*down;
	void	*right;
	void	*ghost1;
	void	*ghost2;
	void	*ghost3;
	void	*ghost4;
}				t_img;

typedef struct s_enemy {
	int		x;
	int		y;
	int		movx;
	int		movy;
	void	*img;
}				t_enemy;

typedef struct s_text {
	void	*img;
}				t_text;

typedef struct s_vars {
	t_img	img;
	void	*mlx;
	void	*win;
	char	*map;
	char	*temp[50];
	char	*strmap;
	char	**maps;
	int		fd;
	int		gnlReturn;
	char	*line;
	int		line_count;
	int		c_count;
	int		e_count;
	int		p_count;
	int		err_count;
	int		width;
	int		win_width;
	int		win_height;
	int		pos_x;
	int		pos_y;
	int		move_count;
	void	*enemy2;
	void	*enemy3;
	int		enemy_count;
	t_enemy	enemy[50];
	t_text	floor[8];
	t_text	coin[6];
	t_text	exit[3];
	t_text	plrw[3];
	t_text	plra[3];
	t_text	plrs[3];
	t_text	plrd[3];
	t_text	ghost1[3];
	t_text	ghost2[3];
	t_text	ghost3[3];
	t_text	ghost4[3];
	int		move_enemy;
	int		animation_floor;
	int		animation_enp;
	int		animation_coin;
	int		animation_exit;
}				t_vars;

enum {
	kVK_ANSI_A = 0x00,
	kVK_ANSI_S = 0x01,
	kVK_ANSI_D = 0x02,
	kVK_ANSI_W = 0x0D,
	kVK_Escape = 0x35,
};

int		main(int argc, char **argv);

int		ft_is_map_valid(t_vars *vars);

void	ft_set_img(t_vars *vars);
void	*read_tileset(t_vars *vars, char *path);

int		deal_key(int key, t_vars *vars);
int		ft_parse_tiles(t_vars *vars);
void	ft_parse_tiles2(t_vars *vars, int i, int j);

void	find_spawn(t_vars *vars);
void	print_nbmoves(t_vars *vars);

void	finish_map(t_vars *vars);
int		close_win(t_vars *vars);

void	move_enemy(t_vars *vars);
void	print_ghosts(t_vars *vars, int i, int j);
void	add_enemy(t_vars *vars);
void	replace_ghosts(t_vars *vars);
void	ft_check_enemy(t_vars *vars, int y, int x);

void	manage_timer(t_vars *vars);
void	free_maps(t_vars *vars);

#endif