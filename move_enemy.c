/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:13:24 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/09 11:46:23 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy3(t_vars *vars, t_enemy *enemy)
{
	if (enemy->movy != 0)
	{
		if (vars->maps[enemy->x][enemy->y + enemy->movy] == '1'
			|| vars->maps[enemy->x][enemy->y + enemy->movy] == 'C')
		{
			if (enemy->movy == 1)
			{
				enemy->movy = -1;
				enemy->img = vars->img.ghost2;
			}
			else if (enemy->movy == -1)
			{
				enemy->movy = 1;
				enemy->img = vars->img.ghost3;
			}
		}
		enemy->y += enemy->movy;
	}
}

void	move_enemy2(t_vars *vars, t_enemy *enemy)
{
	if (enemy->movx != 0)
	{
		if (vars->maps[enemy->x + enemy->movx][enemy->y] == '1'
			|| vars->maps[enemy->x + enemy->movx][enemy->y] == 'C')
		{
			if (enemy->movx == 1)
			{
				enemy->movx = -1;
				enemy->img = vars->img.ghost4;
			}
			else if (enemy->movx == -1)
			{
				enemy->movx = 1;
				enemy->img = vars->img.ghost1;
			}
		}
		enemy->x += enemy->movx;
	}
	else
		move_enemy3(vars, enemy);
}

void	move_enemy(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < vars->enemy_count)
	{
		move_enemy2(vars, &vars->enemy[i]);
		x = vars->enemy[i].x;
		y = vars->enemy[i].y;
		if (y == vars->pos_x && x == vars->pos_y)
		{
			ft_printf("%s%s\n", RED, "Game Over!");
			while (vars->line_count >= 0)
				free (vars->maps[vars->line_count--]);
			free(vars->maps);
			mlx_destroy_window(vars->mlx, vars->win);
			exit (0);
		}
		if (vars->enemy[i].movx != 0)
			vars->maps[x][y] = '3';
		else if (vars->enemy[i].movy != 0)
			vars->maps[x][y] = '2';
		i++;
	}
}
