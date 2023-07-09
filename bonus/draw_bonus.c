/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:47 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 17:18:45 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_line(struct s_data *data, int y_start, int x_start)
{
	int	k;

	data->line.x1 = x_start;
	data->line.y1 = y_start;
	data->line.dx = data->line.end_x - x_start;
	data->line.dy = data->line.end_y - y_start;
	if (abs(data->line.dx) > abs(data->line.dy))
		data->line.steps = abs(data->line.dx);
	else
		data->line.steps = abs(data->line.dy);
	data->line.x_increment = data->line.dx / data->line.steps;
	data->line.y_increment = data->line.dy / data->line.steps;
	k = 0;
	while (k <= data->line.steps)
	{
		my_mlx_pixel_put(data->img, (data->line.x1 * data->scaler_width),
			(data->line.y1 * data->scaler_hight), DARK_YELLOW);
		data->line.x1 += data->line.x_increment;
		data->line.y1 += data->line.y_increment;
		k++;
	}
}

void	draw_line_clear_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->line.end_x = data->rays[i]->wall_x;
		data->line.end_y = data->rays[i]->wall_y;
		if (i == WIDTH / 2)
			draw_line(data, data->player.player_y, data->player.player_x);
		free(data->rays[i]);
		i++;
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
					* data->scaler_hight), RED);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data, char **new)
{
	int	i;
	int	j;

	j = 0;
	while (new[j])
	{
		i = 0;
		while (new[j][i])
		{
			if (new[j][i] == 'N' || new[j][i] == 'S' || new[j][i] == 'E'
				|| new[j][i] == 'W')
				draw_player_pixels(data, (data->player.player_x),
					data->player.player_y);
			i++;
		}
		j++;
	}
	draw_line_clear_rays(data);
}
