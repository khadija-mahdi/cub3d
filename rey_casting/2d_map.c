/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 18:48:07 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	draw_wall(t_img *img, int i, int j, int clr)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i * BLOCK_SIZE - 1;
    y_start = j * BLOCK_SIZE - 1;
	y = y_start;
    while (y < y_start + BLOCK_SIZE - 1)
    {
		x = x_start;
        while (x < x_start + BLOCK_SIZE - 1)
		{
            my_mlx_pixel_put(img, x, y,clr);
			x++;	
		}
		y++;
    }
}

void	draw_player(t_img *img, int i, int j)
{
	int x_start;
	int y_start;
	int	y;
	int x;

	x_start = i * BLOCK_SIZE - 1;
    y_start = j * BLOCK_SIZE - 1;
	y = y_start;
    while (y < y_start + (BLOCK_SIZE / 2) - 1)
    {
		x = x_start;
        while (x <  x_start + (BLOCK_SIZE / 2) - 1)
		{
        	my_mlx_pixel_put(img, x, y, 0xFFFF00);
			x++;
		}
		y++;
    }
}

void draw_2d_map(t_img *img, t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map[j])
	{
		i  = 0;
		while(data->map[j][i])
		{
			if(data->map[j][i] == '0')
				draw_wall(img, i ,j, 0x000000);
			else if (data->map[j][i] == '1')
				draw_wall(img, i ,j, 0xFFFFFF);
			else if (data->map[j][i] == 'N')
				draw_player(img, data->player_y, data->player_x);
				
			i++;
		}
		j++;
	}
}