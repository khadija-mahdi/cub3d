/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 21:00:07 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	mini_mlx_pixel_put(t_mini_img *img, int x, int y, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
	
void	draw_line(t_data *data, int y_start, int x_start, int end_y , int end_x, int clr)
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
    for (int k = 0; k <= steps; k++) {
        mini_mlx_pixel_put(data->mini_img, x1, y1, clr);
        x1 += x_increment;
        y1 += y_increment;
	}
}

void	draw_wall(t_mini_img *img, int i, int j, int clr)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i * TILE_SIZE - 1;
    y_start = j * TILE_SIZE - 1;
	y = y_start;
    while (y < y_start + TILE_SIZE - 1)
    {
		x = x_start;
        while (x < x_start + TILE_SIZE - 1)
		{
            mini_mlx_pixel_put(img, x, y,clr);
			x++;	
		}
		y++;
    }
}

void	draw_walls(t_data *data, int clr, char c)
{
	int	i;
	int	j;
	

	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == c)
				draw_wall(data->mini_img, i ,j, clr);
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
			mini_mlx_pixel_put(data->mini_img, x, y, 0xF4C2C2);
			x++;
		}
		y++;
	}
}


void	draw_player(t_data *data)
{
	int	i;
	int	j;

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
}

void draw_feild_de_view(t_data *data)
{
	int i = 0;
	while (i < WIDTH)
	{
		draw_line(data, data->player.player_y, data->player.player_x,
			data->rays[i]->wall_y, data->rays[i]->wall_x, 0XFFF00F);
		i++;
	}
}
void draw_mini_map(t_data *data)
{
	draw_walls(data, 0xFFFFFF, '1');
	draw_player(data);
	cast_rays(data);
}

