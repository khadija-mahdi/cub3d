/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:47 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/15 17:42:23 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	exit_program(int key_code)
{
	exit_msg("Exit the program with the X !!", 0);
	return (0);
}

void render_player(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr , data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,WIDTH, HEIGHT);	
    data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_2d_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

int window_size(t_data *data, double y,double x)
{
	
		
	printf("map : %c\n", data->map->map[((int)data->player.player_y / TILE_SIZE)][(int)data->player.player_x / TILE_SIZE]);
	if (data->map->map[(int)(y / TILE_SIZE)][(int)x / TILE_SIZE] == '1')
		return (0);
	if (y < HEIGHT && (y >= 0)
		&& ((x < WIDTH) && (x  >= 0)))
		return (1);
	else
		return (0);
}

int	key_code(int key_code, t_data *data)
{

	if (key_code == ESC)
		exit_msg("Exit the program with the 'ESC'  button !", 0);
	if (key_code == LEFT_ARROW)
		data->player.rotation_angle -= ROTATION_SPEED;
	if (key_code == RIGHT_ARROW)
		data->player.rotation_angle += ROTATION_SPEED;
	if (key_code == W_UP)
	{
		data->player.player_y -= sin(data->player.rotation_angle) / MOVE_SPEED;
		data->player.player_x -= cos(data->player.rotation_angle) / MOVE_SPEED;
	}
	if (key_code == S_DOWN)
	{
		data->player.player_y += sin(data->player.rotation_angle) / MOVE_SPEED;
		data->player.player_x += cos(data->player.rotation_angle) / MOVE_SPEED;
	}
	if (key_code == A_LEFT)
	{
		data->player.player_y += sin(data->player.rotation_angle + M_PI / 2) / MOVE_SPEED;
		data->player.player_x += cos(data->player.rotation_angle  + M_PI / 2) / MOVE_SPEED;
	}
	if (key_code == D_RIGHT)
	{
		data->player.player_y -= sin(data->player.rotation_angle  + M_PI / 2) / MOVE_SPEED;
		data->player.player_x -= cos(data->player.rotation_angle + M_PI / 2) / MOVE_SPEED;

	}
	render_player(data);
	return (0);
}
