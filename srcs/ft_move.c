/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:47:33 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/07 08:31:32 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_deal_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->pos_x;
	y = vars->pos_y;
	if (vars->maps[y - 1][x] != '1')
	{
		ft_check_enemy(vars, y - 1, x);
		if (vars->maps[y - 1][x] == 'E')
		{
			if (vars->c_count == 0)
				finish_map(vars);
		}
		else
		{
			if (vars->maps[y - 1][x] == '0' || vars->maps[y - 1][x] == 'C')
			{
				if (vars->maps[y - 1][x] == 'C')
					vars->c_count--;
				vars->maps[y][x] = '0';
				vars->maps[y - 1][x] = 'U';
			}
			vars->move_count++;
		}
	}
}

void	ft_deal_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->pos_x;
	y = vars->pos_y;
	if (vars->maps[y][x - 1] != '1')
	{
		ft_check_enemy(vars, y, x - 1);
		if (vars->maps[y][x - 1] == 'E')
		{
			if (vars->c_count == 0)
				finish_map(vars);
		}
		else
		{
			if (vars->maps[y][x - 1] == '0' || vars->maps[y][x - 1] == 'C')
			{
				if (vars->maps[y][x - 1] == 'C')
					vars->c_count--;
				vars->maps[y][x] = '0';
				vars->maps[y][x - 1] = 'L';
			}
			vars->move_count++;
		}
	}
}

void	ft_deal_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->pos_x;
	y = vars->pos_y;
	if (vars->maps[y + 1][x] != '1')
	{
		ft_check_enemy(vars, y + 1, x);
		if (vars->maps[y + 1][x] == 'E')
		{
			if (vars->c_count == 0)
				finish_map(vars);
		}
		else
		{
			if (vars->maps[y + 1][x] == '0' || vars->maps[y + 1][x] == 'C')
			{
				if (vars->maps[y + 1][x] == 'C')
					vars->c_count--;
				vars->maps[y][x] = '0';
				vars->maps[y + 1][x] = 'D';
			}
			vars->move_count++;
		}
	}
}

void	ft_deal_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->pos_x;
	y = vars->pos_y;
	if (vars->maps[y][x + 1] != '1')
	{
		ft_check_enemy(vars, y, x + 1);
		if (vars->maps[y][x + 1] == 'E' )
		{
			if (vars->c_count == 0)
				finish_map(vars);
		}
		else
		{
			if (vars->maps[y][x + 1] == '0' || vars->maps[y][x + 1] == 'C')
			{
				if (vars->maps[y][x + 1] == 'C')
					vars->c_count--;
				vars->maps[y][x] = '0';
				vars->maps[y][x + 1] = 'R';
			}
			vars->move_count++;
		}
	}
}

int	deal_key(int key, t_vars *vars)
{
	find_spawn(vars);
	if (key == kVK_Escape)
		close_win(vars);
	if (key == kVK_ANSI_W)
		ft_deal_up(vars);
	if (key == kVK_ANSI_A)
		ft_deal_left(vars);
	if (key == kVK_ANSI_S)
		ft_deal_down(vars);
	if (key == kVK_ANSI_D)
		ft_deal_right(vars);
	return (0);
}
