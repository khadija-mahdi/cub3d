/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/30 04:29:13 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"


void	draw_line(t_data *data, int y_start, int x_start, int end_y, int end_x, int clr)
{
	float	steps;
	int		dx;
	int		dy;
	float	x_increment;
	float	y_increment;
	float	x1;
	float	y1;

	x1 = x_start;
	y1 = y_start;
	dx = end_x - x_start;
	dy = end_y - y_start;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_increment = dx / steps;
	y_increment = dy / steps;
	for (int k = 0; k <= steps; k++)
	{
		my_mlx_pixel_put(data->img, (x1 * data->scaler_width), (y1 * data->scaler_hight), clr);
		x1 += x_increment;
		y1 += y_increment;
	}
}

void	draw_wall(t_data *data, int i, int j, int clr)
{
	int	x_start;
	int	y_start;
	int	y;
	int	x;

	x_start = i * TILE_SIZE - 1;
	y_start = j * TILE_SIZE - 1;
	y = y_start;
	while (y < y_start + TILE_SIZE - 1)
	{
		x = x_start;
		while (x < x_start + TILE_SIZE - 1)
		{
			my_mlx_pixel_put(data->img,( x * data->scaler_width), (y * data->scaler_hight), clr);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_data *data, int clr)
{
	int	i;
	int	j;

	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == '1')
				draw_wall(data, i, j, clr);
			i++;
		}
		j++;
	}
}

void	draw_player_pixels(t_data *data, int i, int j)
{
	int	x_start;
	int	y_start;
	int	y;
	int	x;

	x_start = i - (PLAYER_SIZE / 2);
	y_start = j - (PLAYER_SIZE / 2);

	y = y_start;
	while (y < (y_start + (PLAYER_SIZE)))
	{
		x = x_start;
		while (x < (x_start + (PLAYER_SIZE)))
		{
			my_mlx_pixel_put(data->img, (x * data->scaler_width), (y * data->scaler_hight), 0xF4C2C2);
			x++;
		}
		y++;
	}
}

void	draw_line_clear_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		if ( i == (WIDTH / 2))
			draw_line(data, data->player.player_y, data->player.player_x,
				data->rays[i]->wall_y, data->rays[i]->wall_x, BLACK);
		free(data->rays[i]);
		i++;
	}
}
void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	scaler_width;
	int	scaler_height;

	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'N' || data->map->map[j][i] == 'S'
				|| data->map->map[j][i] == 'E' || data->map->map[j][i] == 'W')
				draw_player_pixels(data, (data->player.player_x ),
					data->player.player_y);
			i++;
		}
		j++;
	}
	draw_line_clear_rays(data);
}

void	draw_mini_map(t_data *data)
{
	data->scaler_hight = 0.25;
	data->scaler_width = 0.25;
	if ((data->map->height * TILE_SIZE) * 0.25 >= HEIGHT / 2)
		data->scaler_hight = 0.10;
	if ((data->map->width * TILE_SIZE) * 0.25 >= WIDTH / 2)
		data->scaler_width = 0.10;
	draw_walls(data, DARK_GREEN);
	draw_player(data);
}
