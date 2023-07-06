/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 17:24:29 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	draw_walls(t_data *data, int clr, char **new)
{
	int	i;
	int	j;

	j = 0;
	while (new && new[j])
	{
		i = 0;
		while (new[j][i])
		{
			draw_wall(data, i, j, WHITE);
			if (new[j][i] == '1')
				draw_wall(data, i, j, clr);
			i++;
		}
		j++;
	}
}
