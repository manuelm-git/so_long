/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:32 by manumart          #+#    #+#             */
/*   Updated: 2023/08/15 16:06:03 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_pointers(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	ft_close(void)
{
	mlx_clear_window((*all()).mlx, (*all()).win);
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).player);
	mlx_destroy_image((*all()).mlx, (*all()).floor);
	mlx_destroy_image((*all()).mlx, (*all()).collect);
	mlx_destroy_image((*all()).mlx, (*all()).exit_f);
	free_map(&(*all()).map);
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	exit(EXIT_SUCCESS);
}

void	exit_game(char *str)
{
	mlx_destroy_image((*all()).mlx, (*all()).player);
	mlx_clear_window((*all()).mlx, (*all()).win);
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).floor);
	mlx_destroy_image((*all()).mlx, (*all()).collect);
	mlx_destroy_image((*all()).mlx, (*all()).exit_f);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}

void	close_path(void)
{
	free_map(&(*all()).map);
	exit(EXIT_FAILURE);
}
