/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:29:34 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/07 09:40:06 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_enemy(t_vars *vars, int y, int x)
{
	if (vars->maps[y][x] == '2' || vars->maps[y][x] == '3')
	{
		ft_printf("%s%s\n", RED, "Game Over!");
		while (vars->line_count >= 0)
			free (vars->maps[vars->line_count--]);
		free(vars->maps);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
}

void	add_enemy2(t_vars *vars, int i, int j)
{
	t_enemy	enemy;

	enemy.x = i;
	enemy.y = j;
	if (vars->maps[i][j] == '3')
	{
		enemy.movx = 1;
		enemy.movy = 0;
		enemy.img = mlx_xpm_file_to_image(vars->mlx, "./tileset/ghost1.xpm",
				&vars->img.width, &vars->img.height);
	}
	else
	{
		enemy.movy = 1;
		enemy.movx = 0;
		enemy.img = mlx_xpm_file_to_image(vars->mlx, "./tileset/ghost3.xpm",
				&vars->img.width, &vars->img.height);
	}
	vars->enemy[vars->enemy_count] = enemy;
	vars->enemy_count++;
}

void	add_enemy(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->line_count)
	{
		j = 0;
		while (j < vars->width)
		{
			if (vars->maps[i][j] == '2' ||vars->maps[i][j] == '3')
				add_enemy2(vars, i, j);
			j++;
		}
		i++;
	}
}

void	replace_ghosts(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->line_count)
	{
		j = 0;
		while (j < vars->width)
		{
			if (vars->maps[i][j] == '2')
				vars->maps[i][j] = '0';
			if (vars->maps[i][j] == '3')
				vars->maps[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	find_spawn(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->line_count)
	{
		i = 0;
		while (i < vars->width)
		{
			if (vars->maps[j][i] == 'P' ||
				vars->maps[j][i] == 'R' ||
				vars->maps[j][i] == 'U' ||
				vars->maps[j][i] == 'D' ||
				vars->maps[j][i] == 'L')
			{
				vars->pos_x = i;
				vars->pos_y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}
