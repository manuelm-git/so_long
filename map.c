/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:04 by manumart          #+#    #+#             */
/*   Updated: 2023/08/15 16:05:35 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line(char *path)
{
	int		fd;
	int		line;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(write(2, "Invalid fd!\n", 12));
	line = 0;
	while (read(fd, &buffer, 1))
		if (buffer == '\n')
			line++;
	close(fd);
	return (line);
}

t_map	get_map(char *path)
{
	int		i;
	int		fd;
	t_map	map;

	map.map_height = get_line(path);
	map.mat = malloc((map.map_height + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (!map.mat || fd < 0 || map.map_height < 2)
	{
		free_pointers(map.mat);
		ft_putstr_fd("Error creating map\n", 1);
		if (fd != -1)
			close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map.map_height)
	{
		map.mat[i] = get_next_line(fd);
		i++;
	}
	map.mat[i] = NULL;
	map.map_width = ft_strlen(map.mat[0]) - 1;
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->mat[i])
		free(map->mat[i++]);
	free(map->mat);
}

t_map	create_map(char *path)
{
	t_map	map;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".ber", 4))
	{
		ft_putstr_fd("ERROR! File related\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map(path);
	if (check_geral(map) == 1)
	{
		ft_putstr_fd("INVALID MAP!\n", 2);
		free_map(&map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
