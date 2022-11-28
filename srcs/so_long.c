/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:23:40 by gasselin          #+#    #+#             */
/*   Updated: 2022/11/28 08:54:55 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	ft_init_vars(char **argv)
{
	t_vars	vars;

	vars.gnlReturn = 0;
	vars.line = NULL;
	vars.line_count = 0;
	vars.width = 0;
	vars.e_count = 0;
	vars.c_count = 0;
	vars.p_count = 0;
	vars.err_count = 0;
	vars.move_count = 0;
	vars.move_enemy = 0;
	vars.enemy_count = 0;
	vars.animation_exit = 0;
	vars.animation_floor = 0;
	vars.animation_coin = 0;
	vars.animation_enp = 0;
	vars.map = argv[1];
	vars.fd = open(vars.map, O_RDWR);
	vars.strmap = NULL;
	return (vars);
}

void	print_nbmoves(t_vars *vars)
{
	char	*str;
	char	*nbr;

	nbr = ft_itoa(vars->move_count);
	str = ft_strjoin("Moves count : ", nbr);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, str);
	free (nbr);
	free (str);
}

void	finish_map(t_vars *vars)
{
	vars->move_count++;
	while (vars->line_count >= 0)
		free (vars->maps[vars->line_count--]);
	free(vars->maps);
	free (vars->strmap);
	mlx_destroy_window(vars->mlx, vars->win);
	printf("Map finished, %d moves\n", vars->move_count);
	exit (0);
}

int	close_win(t_vars *vars)
{
	while (vars->line_count >= 0)
		free (vars->maps[vars->line_count--]);
	free(vars->maps);
	free (vars->strmap);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*str;

	if (argc != 2)
		return (printf("%sError:%s %s\n", RED, NC, "Invalid arguments"));
	vars = ft_init_vars(argv);
	str = ft_strnstr(vars.map, ".ber", ft_strlen(vars.map));
	if (vars.fd == -1 || !str || ft_strlen(str) != 4)
		return (printf("%sError:%s %s\n", RED, NC, "Invalid file path"));
	if (ft_is_map_valid(&vars))
	{
		free_maps(&vars);
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"./so_long");
	add_enemy(&vars);
	ft_set_img(&vars);
	mlx_hook(vars.win, 02, 1L << 0, deal_key, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_win, &vars);
	mlx_loop_hook(vars.mlx, ft_parse_tiles, &vars);
	mlx_loop(vars.mlx);
}
