/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:59 by manumart          #+#    #+#             */
/*   Updated: 2023/08/15 16:05:31 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	find_player(char **map)
{
	t_player	coords;

	coords.y = 0;
	while (map[coords.y])
	{
		coords.x = 0;
		while (map[coords.y][coords.x])
		{
			if (map[coords.y][coords.x] == 'P')
			{
				return (coords);
			}
			coords.x++;
		}
		coords.y++;
	}
	return (coords);
}

int	check_coli(char **map, int x, int y, char c)
{
	t_player	p;

	p = find_player(map);
	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);
}

void	move_player(char **map, int x, int y)
{
	t_player	p;

	p = find_player(map);
	if (check_coli(map, x, y, 'E') && (*all()).nbr_cl == 0)
		exit_game("FIM\n");
	if (!check_coli(map, x, y, '1'))
	{
		if (check_coli(map, x, y, 'C'))
			(*all()).nbr_cl--;
		if (!check_coli(map, x, y, 'E'))
		{
			map[p.y][p.x] = '0';
			map[p.y + y][p.x + x] = 'P';
			(*all()).steps++;
		}
	}
}
