/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 07:06:56 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/11 11:45:59 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

t_data	*init_data(t_data *data, struct s_map  *map)
{
	data = malloc(sizeof(t_data));
	data->map = map;
	data->is_player = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "The_KM_game!");
	data->img = malloc(sizeof(t_img));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,WIDTH, HEIGHT);	
    data->img->addr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	init_pos(data);
	data->player_x = data->map->x * TILE_SIZE + (TILE_SIZE / 2 - P_SIZ);
	data->player_y = data->map->y * TILE_SIZE + (TILE_SIZE / 2 - P_SIZ);
	return(data);
}

// t_player player(t_player player)
// {
// 	player.rotation_angle = PI / 2;
// 	player.walk_speed = 100;
// 	player.turn_speed = 45 * (PI / 180);
// }

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
