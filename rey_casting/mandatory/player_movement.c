/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:45:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 20:26:55 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"

void	player_pos(t_data *data)
{
	if (data->dir_keys[0] == RIGHT_ARROW)
	{
		data->player.rotation_angle += ROTATION_SPEED;
		if (data->player.rotation_angle > 2 * M_PI)
			data->player.rotation_angle -= 2 * M_PI;
	}
	else if (data->dir_keys[0] == LEFT_ARROW)
	{
		data->player.rotation_angle -= ROTATION_SPEED;
		if (data->player.rotation_angle < 0)
			data->player.rotation_angle += 2 * M_PI;
	}
	if (data->dir_keys[1] == A_LEFT)
		move_left(data);
	else if (data->dir_keys[1] == D_RIGHT)
		move_right(data);
	if (data->dir_keys[2] == W_UP)
		move_up(data);
	else if (data->dir_keys[2] == S_DOWN)
		move_down(data);
}

int	key_press(int key_code, t_data *data)
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

int	key_code(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	player_pos(data);
	render_player(data);
	return (0);
}
