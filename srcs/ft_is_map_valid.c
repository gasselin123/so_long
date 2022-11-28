/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:22:14 by gasselin          #+#    #+#             */
/*   Updated: 2022/11/28 08:54:20 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_eol(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->strmap[i])
	{
		if (vars->strmap[i] == '\n')
			if (vars->strmap[i + 1] == '\n')
				return (1);
		i++;
	}
	return (0);
}

int	ft_is_map_valid4(t_vars *vars)
{
	int	i;

	while (vars->maps[vars->line_count] != NULL)
	{
		i = vars->line_count++;
		if (ft_strlen(vars->maps[i]) != (size_t)vars->width
			|| vars->maps[i][0] != '1'
			|| vars->maps[i][vars->width - 1] != '1')
			return (printf("%sError:%s %s\n", RED, NC, "Invalid map"));
	}
	i = 1;
	vars->win_height = vars->line_count * 32;
	vars->win_width = vars->width * 32;
	while (i < vars->line_count)
	{
		if (i == vars->line_count - 1)
			if (ft_strchr_rev(vars->maps[i], '1'))
				return (printf("%sError:%s %s\n", RED, NC, "Invalid map"));
		i++;
	}
	return (0);
}

int	ft_is_map_valid3(t_vars *vars)
{
	if (check_eol(vars))
		return (printf("%sError:%s %s\n", RED, NC, "Invalid map"));
	vars->c_count = ft_count_char(vars->strmap, "C");
	vars->p_count = ft_count_char(vars->strmap, "P");
	vars->e_count = ft_count_char(vars->strmap, "E");
	vars->err_count = (ft_strlen(vars->strmap) - ft_count_char(vars->strmap,
				"CPE0123\n"));
	if (vars->e_count != 1 || vars->p_count != 1 || vars->c_count == 0
		|| vars->err_count > 0)
		return (printf("%sError:%s %s\n", RED, NC, "Invalid map"));
	vars->maps = ft_split(vars->strmap, '\n');
	if (ft_strchr_rev(vars->maps[0], '1'))
		return (printf("%sError:%s %s\n", RED, NC, "Invalid map"));
	vars->width = ft_strlen(vars->maps[vars->line_count++]);
	return (ft_is_map_valid4(vars));
}

int	ft_is_map_valid2(t_vars *vars, char c, int length)
{
	char	*tmp;
	int		i;

	tmp = malloc(length);
	if (!tmp)
	{
		free(vars->strmap);
		return (-1);
	}
	i = -1;
	while (++i < length - 2)
		tmp[i] = vars->strmap[i];
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(vars->strmap);
	vars->strmap = tmp;
	return (0);
}

int	ft_is_map_valid(t_vars *vars)
{
	char	c;
	int		length;
	int		reading;
	char	*tmp;

	length = 1;
	reading = 1;
	vars->strmap = malloc(length);
	vars->strmap[0] = 0;
	while (reading == 1 && length++)
	{
		reading = read(vars->fd, &c, 1);
		if (reading != 1)
			break ;
		if (ft_is_map_valid2(vars, c, length) == -1)
			return (printf("%sError:%s %s\n", RED, NC, "Malloc failed"));
	}
	close (vars->fd);
	tmp = ft_strtrim(vars->strmap, "\n");
	free (vars->strmap);
	vars->strmap = tmp;
	return (ft_is_map_valid3(vars));
}
