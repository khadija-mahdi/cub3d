/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/12 17:52:54 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"


void	draw_wall(t_img *img, int i, int j, int clr)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i * TILE_SIZE;
    y_start = j * TILE_SIZE;
	y = y_start;
    while (y < y_start + TILE_SIZE)
    {
		x = x_start;
        while (x < x_start + TILE_SIZE)
		{
            my_mlx_pixel_put(img, x, y,clr);
			x++;	
		}
		y++;
    }
}

void	draw_line(t_data *data, int y_start, int x_start, int end_y , int end_x)
{
    float	steps;
	int		dx;
	int		dy;
	float x_increment;
	float y_increment;
	float x1;
	float y1;

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
    for (int k = 0; k <= steps; k++) {
        my_mlx_pixel_put(data->img, x1, y1, 0xFF0000);
        x1 += x_increment;
        y1 += y_increment;
    }
}

void	draw_walls(t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map->map[j])
	{
		i  = 0;
		while(data->map->map[j][i])
		{
			if (data->map->map[j][i] == '1')
				draw_wall(data->img, i ,j, 0xFFFFFF);
			i++;
		}
		j++;
	}
}

void	draw_player_pixels(t_data *data, int i, int j)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i;
    y_start = j;
	y = y_start;
    while (y < (y_start + PLAYER_SIZE))
    {
		x = x_start;
        while (x < (x_start + PLAYER_SIZE)) 
		{
        	my_mlx_pixel_put(data->img, x, y, 0xF4C2C2);
			x++;
		}
		y++;
    }
	draw_line(data, y_start, x_start, (HEIGHT - 100),( WIDTH - 100));
}


void	draw_player(t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map->map[j])
	{
		i  = 0;
		while(data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'N' || data->map->map[j][i] == 'S'
				|| data->map->map[j][i] == 'E' || data->map->map[j][i] == 'W')
				draw_player_pixels(data, data->player.player_x, data->player.player_y);
			i++;
		}
		j++;
	}
}

void draw_2d_map(t_data *data)
{
	draw_walls(data);
	draw_player(data);
}
