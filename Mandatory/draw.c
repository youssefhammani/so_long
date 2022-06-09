/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhammani <yhammani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 04:14:37 by yhammani          #+#    #+#             */
/*   Updated: 2022/02/17 16:28:43 by yhammani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->field[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_wall, j * 48, i * 48);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, \
				map->texture_floor, j * 48, i * 48);
				if (map->field[i][j] == 'P')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_mouse, j * 48, i * 48);
				else if (map->field[i][j] == 'C')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_cheese, j * 48, i * 48);
				else if (map->field[i][j] == 'E')
					mlx_put_image_to_window(map->mlx, map->mlx_win, \
					map->texture_exit, j * 48, i * 48);
			}
		}
	}
}

void	game_init(t_map *map)
{
	map->texture_mouse = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/mouse_right.xpm", &map->img_width, &map->img_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/mouse_house.xpm", &map->img_width, &map->img_width);
	map->texture_floor = mlx_xpm_file_to_image(map->mlx, \
	"MAndatory/Xpms/floor.xpm", &map->img_width, &map->img_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/wall.xpm", &map->img_width, &map->img_height);
	map->texture_cheese = mlx_xpm_file_to_image(map->mlx, \
	"Mandatory/Xpms/cheese.xpm", &map->img_width, &map->img_height);
	if (!map->texture_mouse || !map->texture_exit || !map->texture_floor \
		|| !map->texture_wall || !map->texture_cheese)
	{
		perror("Error with xpm files");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
