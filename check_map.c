/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:40 by manumart          #+#    #+#             */
/*   Updated: 2023/08/22 20:17:51 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_side(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_height)
	{
		if (map.mat[i][0] != '1' || map.mat[i][map.map_width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_top_bot(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_width - 1)
	{
		if (map.mat[0][i] != '1' || map.mat[map.map_height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_other(t_map map, int y, int x, int player)
{
	static int	exit;
	static int	collect;

	while (map.mat[y])
	{
		x = 0;
		while (map.mat[y][x])
		{
			if (map.mat[y][x] == 'P')
				player++;
			else if (map.mat[y][x] == 'E')
				exit++;
			else if (map.mat[y][x] == 'C')
				collect++;
			else if (map.mat[y][x] != '1' && map.mat[y][x] != '0'
					&& map.mat[y][x] != '\n')
				return (1);
			x++;
		}
		y++;
	}
	if (check_quanti(player, exit, collect) == 1)
		return (1);
	return (0);
}

static int	check_formato(t_map map)
{
	int width;
	int i;
	
	i = 0;
	width = ft_strlen(map.mat[0]);
	while (++i < map.map_height)
		{
			if (ft_strlen(map.mat[i]) != width)
				return (1);
		}
	return (0);
}

int	check_geral(t_map map)
{
	if (check_formato(map) == 1)
	{
		ft_putstr_fd("The map incorrect!\n", 2);
		return (1);
	}
	if (check_top_bot(map) == 1 || check_side(map) == 1)
	{
		ft_putstr_fd("The map is not closed!\n", 2);
		return (1);
	}
	if (check_other(map, 0, 0, 0) == 1)
	{
		return (1);
	}
	return (0);
}
