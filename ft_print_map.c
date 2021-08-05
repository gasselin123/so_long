/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:28:50 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/13 15:24:54 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parse_tiles2(t_vars *vars, int i, int j)
{
	if (vars->maps[i][j] != '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor[vars->animation_floor / 10].img, j * 32, i * 32);
	if (vars->maps[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall,
			j * 32, i * 32);
	if (vars->maps[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->coin[vars->animation_coin / 10].img, j * 32, i * 32);
	if (vars->maps[i][j] == 'P' || vars->maps[i][j] == 'D')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->plrs[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->maps[i][j] == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->plrw[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->maps[i][j] == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->plra[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->maps[i][j] == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->plrd[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->maps[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit[vars->animation_exit / 30].img, j * 32, i * 32);
	print_ghosts(vars, i, j);
}

int	ft_parse_tiles(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	find_spawn(vars);
	manage_timer(vars);
	while (i < vars->line_count)
	{
		j = 0;
		while (j < vars->width)
		{
			ft_parse_tiles2(vars, i, j);
			j++;
		}
		i++;
	}
	print_nbmoves(vars);
	return (0);
}

void	ft_set_img2(t_vars *vars)
{
	vars->plra[0].img = read_tileset(vars, "./tileset/left.xpm");
	vars->plra[1].img = read_tileset(vars, "./tileset/left1.xpm");
	vars->plra[2].img = read_tileset(vars, "./tileset/left2.xpm");
	vars->plrs[0].img = read_tileset(vars, "./tileset/down.xpm");
	vars->plrs[1].img = read_tileset(vars, "./tileset/down1.xpm");
	vars->plrs[2].img = read_tileset(vars, "./tileset/down2.xpm");
	vars->plrd[0].img = read_tileset(vars, "./tileset/right.xpm");
	vars->plrd[1].img = read_tileset(vars, "./tileset/right1.xpm");
	vars->plrd[2].img = read_tileset(vars, "./tileset/right2.xpm");
	vars->ghost1[0].img = read_tileset(vars, "./tileset/ghost1.xpm");
	vars->ghost1[1].img = read_tileset(vars, "./tileset/ghost1-1.xpm");
	vars->ghost1[2].img = read_tileset(vars, "./tileset/ghost1-2.xpm");
	vars->ghost2[0].img = read_tileset(vars, "./tileset/ghost2.xpm");
	vars->ghost2[1].img = read_tileset(vars, "./tileset/ghost2-1.xpm");
	vars->ghost2[2].img = read_tileset(vars, "./tileset/ghost2-2.xpm");
	vars->ghost3[0].img = read_tileset(vars, "./tileset/ghost3.xpm");
	vars->ghost3[1].img = read_tileset(vars, "./tileset/ghost3-1.xpm");
	vars->ghost3[2].img = read_tileset(vars, "./tileset/ghost3-2.xpm");
	vars->ghost4[0].img = read_tileset(vars, "./tileset/ghost4.xpm");
	vars->ghost4[1].img = read_tileset(vars, "./tileset/ghost4-1.xpm");
	vars->ghost4[2].img = read_tileset(vars, "./tileset/ghost4-2.xpm");
}

void	ft_set_img(t_vars *vars)
{
	vars->img.wall = read_tileset(vars, "./tileset/wall.xpm");
	vars->exit[0].img = read_tileset(vars, "./tileset/exit.xpm");
	vars->exit[1].img = read_tileset(vars, "./tileset/exit1.xpm");
	vars->exit[2].img = read_tileset(vars, "./tileset/exit2.xpm");
	vars->coin[0].img = read_tileset(vars, "./tileset/coin1.xpm");
	vars->coin[1].img = read_tileset(vars, "./tileset/coin2.xpm");
	vars->coin[2].img = read_tileset(vars, "./tileset/coin3.xpm");
	vars->coin[3].img = read_tileset(vars, "./tileset/coin4.xpm");
	vars->coin[4].img = read_tileset(vars, "./tileset/coin5.xpm");
	vars->coin[5].img = read_tileset(vars, "./tileset/coin6.xpm");
	vars->floor[0].img = read_tileset(vars, "./tileset/floor.xpm");
	vars->floor[1].img = read_tileset(vars, "./tileset/floor1.xpm");
	vars->floor[2].img = read_tileset(vars, "./tileset/floor2.xpm");
	vars->floor[3].img = read_tileset(vars, "./tileset/floor3.xpm");
	vars->floor[4].img = read_tileset(vars, "./tileset/floor4.xpm");
	vars->floor[5].img = read_tileset(vars, "./tileset/floor5.xpm");
	vars->floor[6].img = read_tileset(vars, "./tileset/floor6.xpm");
	vars->floor[7].img = read_tileset(vars, "./tileset/floor7.xpm");
	vars->plrw[0].img = read_tileset(vars, "./tileset/up.xpm");
	vars->plrw[1].img = read_tileset(vars, "./tileset/up1.xpm");
	vars->plrw[2].img = read_tileset(vars, "./tileset/up2.xpm");
	ft_set_img2(vars);
}
