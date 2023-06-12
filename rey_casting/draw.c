/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:47 bjkmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 11:24:24 by kmahdi           ###   ########.fr       */
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

int window_size(t_data *data, int y, int x)
{
	if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == '1')
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
	if (key_code == W_UP && window_size(data, data->player.player_y - 1, data->player.player_x))
		data->player.player_y -= 1 * data->player.player_speed;
	else if (key_code == S_DOWN && window_size(data, ((data->player.player_y + 1) + PLAYER_SIZE) , data->player.player_x))
		data->player.player_y += 1 * data->player.player_speed;
	else if (key_code == D_RIGHT && window_size(data, data->player.player_y,((data->player.player_x + 1) + PLAYER_SIZE)))
		data->player.player_x += 1 * data->player.player_speed;
	else if (key_code == A_LEFT && window_size(data, data->player.player_y , data->player.player_x - 1))
		data->player.player_x -= 1 * data->player.player_speed;
	// else if (key_code == LEFT_ARROW)
	// 	data->player.player_y = data->player.player_y;
	// else if (key_code == RIGHT_ARROW)
	// 	data->player.player_y = data->player.player_player_y;
	render_player(data);
	return (0);
}
