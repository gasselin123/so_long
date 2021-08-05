/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:13:11 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/13 15:12:42 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ghosts2(t_vars *vars, int i, int j, int n)
{
	if (vars->enemy[n].movx == 0 && vars->enemy[n].movy == 1)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ghost3[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->enemy[n].movx == 0 && vars->enemy[n].movy == -1)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ghost2[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->enemy[n].movx == 1 && vars->enemy[n].movy == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ghost1[vars->animation_enp / 30].img, j * 32, i * 32);
	if (vars->enemy[n].movx == -1 && vars->enemy[n].movy == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ghost4[vars->animation_enp / 30].img, j * 32, i * 32);
}

void	print_ghosts(t_vars *vars, int i, int j)
{
	int	n;

	n = 0;
	while (n < vars->enemy_count)
	{
		if (i == vars->enemy[n].x && j == vars->enemy[n].y)
		{
			print_ghosts2(vars, i, j, n);
			break ;
		}
		n++;
	}
}

void	*read_tileset(t_vars *vars, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	close (fd);
	if (fd == -1)
	{
		ft_printf("%sError:%s %s\n", RED, NC, "Invalid texture path");
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (mlx_xpm_file_to_image(vars->mlx, path, &vars->img.width,
			&vars->img.height));
}

void	free_maps(t_vars *vars)
{
	int	i;

	i = 0;
	free (vars->strmap);
	if (vars->maps)
	{
		while (vars->maps[i] != NULL)
			free (vars->maps[i++]);
		free(vars->maps);
	}
}
