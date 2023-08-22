/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:00:43 by manumart          #+#    #+#             */
/*   Updated: 2023/08/22 19:16:11 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

//get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//player merdas
typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

//mapa merdas
typedef struct s_map
{
	int		map_height;
	int		map_width;
	char	**mat;
}			t_map;

//mlx merdas
typedef struct s_all
{
	t_map	map;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit_f;
	int		nbr_cl;
	int		steps;

}			t_all;

//main
t_all		*all(void);

//map
int			check_geral(t_map map);
t_map		create_map(char *path);
int			check_elements(t_map map, char c);
void		free_map(t_map *map);
int			check_quanti(int player, int exit, int collect);
char		**map_copy(void);

//keys
int			handle_keys(int o);

//close_game
int			ft_close(void);
void		exit_game(char *str);
void		close_path(void);

//path
int			check_path(void);
void		free_pointers(char **matrix);

//img
void		put_img(char **map, t_all img);

//player
t_player	find_player(char **map);
void		move_player(char **map, int x, int y);

//get_next_line
char		*get_next_line(int fd);
int			stashfree(char *str);
char		*ft_strjoin_gnl(char *str1, char *str2);
size_t		ft_strlen_gnl(char *str);

#endif