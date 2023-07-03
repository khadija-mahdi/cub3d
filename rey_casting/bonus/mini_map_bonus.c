/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 20:46:33 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"

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
			my_mlx_pixel_put(data->img, (x * data->scaler_width), (y
					* data->scaler_hight), clr);
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
			my_mlx_pixel_put(data->img, (x * data->scaler_width), (y
					* data->scaler_hight), 0xF4C2C2);
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
		if (i == (WIDTH / 2))
		{
			data->line.end_x = data->rays[i]->wall_x;
			data->line.end_y = data->rays[i]->wall_y;
			draw_line(data, data->player.player_y, data->player.player_x);
		}
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
				draw_player_pixels(data, (data->player.player_x),
					data->player.player_y);
			i++;
		}
		j++;
	}
	draw_line_clear_rays(data);
}
