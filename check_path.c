/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:36 by manumart          #+#    #+#             */
/*   Updated: 2023/08/22 15:31:32 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_copy(void)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = ft_calloc((*all()).map.map_height + 1, sizeof(char *));
	if (!copy)
		return (0);
	while (i < (*all()).map.map_height)
	{
		copy[i] = ft_calloc((*all()).map.map_width + 1, sizeof(char *));
		j = 0;
		if (!copy[i])
		{
			free_pointers(copy);
			return (0);
		}
		while (j < (*all()).map.map_width)
		{
			copy[i][j] = (*all()).map.mat[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

static int	count_collect(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				count++;
		y++;
	}
	return (count);
}

static void	find_path_collect(char **tmp, int x, int y)
{
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V' && tmp[y][x + 1] != 'E')
		find_path_collect(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V' && tmp[y][x - 1] != 'E')
		find_path_collect(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V' && tmp[y + 1][x] != 'E')
		find_path_collect(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V' && tmp[y - 1][x] != 'E')
		find_path_collect(tmp, x, y - 1);
}

static int	find_path_exit(char **tmp, int x, int y)
{
	static int	exit;

	if (tmp[y][x] == 'E')
		exit++;
	tmp[y][x] = 'V';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'V')
		find_path_exit(tmp, x + 1, y);
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'V')
		find_path_exit(tmp, x - 1, y);
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'V')
		find_path_exit(tmp, x, y + 1);
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'V')
		find_path_exit(tmp, x, y - 1);
	return (exit);
}

int	check_path(void)
{
	char		**tmp;
	int			collect;
	int			valid;
	t_player	p;

	tmp = map_copy();
	if (!tmp)
		return (0);
	p = find_player(tmp);
	find_path_collect(tmp, p.x, p.y);
	collect = count_collect(tmp);
	free_pointers(tmp);
	tmp = map_copy();
	valid = (find_path_exit(tmp, p.x, p.y) && !collect);
	free_pointers(tmp);
	if (!valid)
	{
		ft_putstr_fd("ERROR!\n The player won't be able to find an exit", 2);
		return (0);
	}
	return (1);
}
