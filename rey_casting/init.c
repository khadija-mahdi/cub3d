/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 07:06:56 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/26 22:13:00 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	init_player_directions(t_data *data, int y, int x)
{
	if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'W')
		data->player.rotation_angle = 0;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'E')
		data->player.rotation_angle = M_PI;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'N')
		data->player.rotation_angle = M_PI / 2;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'S')
		data->player.rotation_angle = 3 * M_PI / 2;
}

void	player_init(t_data *data)
{
	data->player.player_x = data->map->x * (TILE_SIZE) + (TILE_SIZE / 2);
	data->player.player_y = data->map->y * (TILE_SIZE) + (TILE_SIZE / 2);
	init_player_directions(data, data->player.player_y, data->player.player_x);
}

void	init_window_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
			"The_KM_game!");
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		return;
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH,
			HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
}

t_data	*init_data(t_data *data, struct s_map_info *map)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map;
	init_window_img(data);
	data->rays = malloc(sizeof(t_rey *) * WIDTH);
	player_init(data);
	data->dir_keys[0] = -1;
	data->dir_keys[1] = -1;
	data->dir_keys[2] = -1;
	data->dir_mouse[0] = -1;
	data->dir_mouse[1] = -1;
	return (data);
}
