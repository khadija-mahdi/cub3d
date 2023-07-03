/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:47 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 20:46:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rey_casting_bonus.h"

int	handle_mouse_click(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = button;
	return (0);
}

int	release_mouse(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = 0;
	return (0);
}

int	key_press_bonus(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_msg("exit with esc key", 0);
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = key_code;
	else if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = key_code;
	else if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = key_code;
	return (0);
}

void	draw_line(t_data *data, int y_start, int x_start)
{
	int		k;

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
			(data->line.y1 * data->scaler_hight), BLACK);
		data->line.x1 += data->line.x_increment;
		data->line.y1 += data->line.y_increment;
		k++;
	}
}
