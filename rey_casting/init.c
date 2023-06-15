/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 07:06:56 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/15 17:40:08 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	init_player_dircetions(t_data *data, int y, int x)
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
	init_pos(data);
	data->player.player_x = data->map->x * TILE_SIZE;
	data->player.player_y = data->map->y * TILE_SIZE;
	init_player_dircetions(data, data->player.player_y, data->player.player_x);
}

void	init_window_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "The_KM_game!");
	data->img = malloc(sizeof(t_img));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,WIDTH, HEIGHT);	
    data->img->addr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
}

t_data	*init_data(t_data *data, struct s_map  *map)
{
	data = malloc(sizeof(t_data));
	data->map = map;
	init_window_img(data);
	player_init(data);
	return(data);
}
