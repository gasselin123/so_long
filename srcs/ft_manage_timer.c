/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_timer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:31:17 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/12 11:13:31 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_timer(t_vars *vars)
{
	if (vars->move_enemy < 0)
		vars->move_enemy = 0;
	if (++vars->move_enemy > 74)
	{
		vars->move_enemy = 0;
		replace_ghosts(vars);
		move_enemy(vars);
	}
	if (++vars->animation_enp > 89 || vars->animation_enp < 0)
		vars->animation_enp = 0;
	if (++vars->animation_exit > 89 || vars->animation_exit < 0)
		vars->animation_exit = 0;
	if (++vars->animation_coin > 59 || vars->animation_coin < 0)
		vars->animation_coin = 0;
	if (++vars->animation_floor > 79 || vars->animation_floor < 0)
		vars->animation_floor = 0;
}
