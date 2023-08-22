/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:01:21 by manumart          #+#    #+#             */
/*   Updated: 2023/08/15 16:05:55 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int o)
{
	if (o == XK_Escape)
		ft_close();
	else if (o == XK_w)
		move_player((*all()).map.mat, 0, -1);
	else if (o == XK_s)
		move_player((*all()).map.mat, 0, 1);
	else if (o == XK_d)
		move_player((*all()).map.mat, 1, 0);
	else if (o == XK_a)
		move_player((*all()).map.mat, -1, 0);
	mlx_clear_window((*all()).mlx, (*all()).win);
	put_img((*all()).map.mat, (*all()));
	return (1);
}
