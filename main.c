/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:16 by manumart          #+#    #+#             */
/*   Updated: 2023/08/22 16:10:54 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

void	init_img(t_all *img)
{
	int	i;

	i = 0;
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/wall.xpm", &i, &i);
	img->floor = mlx_xpm_file_to_image(img->mlx, "img/floor.xpm", &i, &i);
	img->collect = mlx_xpm_file_to_image(img->mlx, "img/collect.xpm", &i, &i);
	img->exit_f = mlx_xpm_file_to_image(img->mlx, "img/exit.xpm", &i, &i);
	img->player = mlx_xpm_file_to_image(img->mlx, "img/player.xpm", &i, &i);
	img->nbr_cl = check_elements(img->map, 'C');
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit(write(2, "Error\n", 6));
	(*all()).map = create_map(av[1]);
	if (!check_path())
	{
		close_path();
		return (0);
	}
	(*all()).mlx = mlx_init();
	init_img(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_width * 64,
			(*all()).map.map_height * 64, "so_long");
	mlx_hook((*all()).win, 17, 1, ft_close, NULL);
	mlx_hook((*all()).win, 2, 0, handle_keys, NULL);
	put_img((*all()).map.mat, (*all()));
	mlx_loop((*all()).mlx);
	return (0);
}
