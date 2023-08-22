/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:44 by manumart          #+#    #+#             */
/*   Updated: 2023/08/22 15:51:50 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_quanti(int player, int exit, int collect)
{
	if (player == 0)
	{
		ft_putstr_fd("No player found!\n", 2);
		return (1);
	}
	else if (player > 1)
	{
		ft_putstr_fd("Too many players!", 2);
		return (1);
	}
	else if (exit > 1)
	{
		ft_putstr_fd("Too many exits", 2);
		return (1);
	}
	else if (collect == 0)
	{
		ft_putstr_fd("No collectables!", 2);
		return (1);
	}
	return (0);
}

int	check_elements(t_map map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (j < map.map_width - 1)
		{
			if (map.mat[i][j] == c)
				count++;
			if (map.mat[i][j] != '1' && map.mat[i][j] != '0' &&
				map.mat[i][j] != 'E' && map.mat[i][j] != 'C' &&
				map.mat[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (count);
}
