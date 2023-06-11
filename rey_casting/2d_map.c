/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/11 13:24:38 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"


void	draw_wall(t_img *img, int i, int j, int clr)
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
            my_mlx_pixel_put(img, x, y,clr);
			x++;	
		}
		y++;
    }
}

void	draw_player(t_data *data, int i, int j)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i;
    y_start = j;
	y = y_start;
    while (y < (y_start + P_SIZ) )
    {
		x = x_start;
        while (x < (x_start + P_SIZ)) 
		{
        	my_mlx_pixel_put(data->img, x, y, 0xF4C2C2);
			x++;
		}
		y++;
    }
	// draw_line(data, y_start, x_start);
}

void draw_2d_map(t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map->map[j])
	{
		i  = 0;
		while(data->map->map[j][i])
		{
			// draw_wall(data->img, i ,j, 0x000000);
			if (data->map->map[j][i] == 'N' || data->map->map[j][i] == 'S'
				|| data->map->map[j][i] == 'E' || data->map->map[j][i] == 'W')
				draw_player(data, data->player_y, data->player_x);
			if (data->map->map[j][i] == '1')
				draw_wall(data->img, i ,j, 0xFFFFFF);
				
			i++;
		}
		j++;
	}
}