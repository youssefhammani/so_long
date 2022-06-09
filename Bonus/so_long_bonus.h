/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhammani <yhammani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 04:19:20 by yhammani          #+#    #+#             */
/*   Updated: 2022/02/18 04:22:53 by yhammani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	char	**field;
	int		player;
	int		exit;
	int		collect;
	int		trap;
	int		p_x;
	int		p_y;
	int		height;
	int		width;
	int		img_height;
	int		img_width;
	int		steps;
	void	*texture_mouse;
	void	*texture_floor;
	void	*texture_wall;
	void	*texture_cheese;
	void	*texture_exit;
	void	*texture_trap;
	void	*texture_black;
	char	direction;
	int		count;
}	t_map;

void	valid_map(t_map *map, int fd, char *av);
void	game_init(t_map *map);
void	map_render(t_map *map, int i, int j);
int		key_hook(int key_code, t_map *map);
int		destroy_window(t_map *map);
int		mouse_update(t_map *map);
void	ft_printf(char *str);

#endif
