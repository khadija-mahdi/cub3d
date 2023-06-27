/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:45:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 21:28:01 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	player_left_right(t_data *data, int key)
{
	double new_x;
	double new_y;

	if (key == 1) // left
	{
		new_x = (data->player.player_x) + cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
		new_y = (data->player.player_y ) + sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
    	if (wall_collision(data, new_y, new_x))
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
	else if (key == 0) //right
	{
		new_x = (data->player.player_x) - cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
		new_y = (data->player.player_y ) - sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
    	if (wall_collision(data, new_y, new_x))
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
}

void player_up_down(t_data *data, int key)
{
	double	new_y;
    double	new_x;

	if (key == 0)
	{
		new_x = (data->player.player_x ) - cos(data->player.rotation_angle) * MOVE_SPEED;
		new_y = (data->player.player_y ) - sin(data->player.rotation_angle) * MOVE_SPEED;
		if (wall_collision(data, new_y, new_x))
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
	if (key == 1)
	{
		new_x = (data->player.player_x ) + cos(data->player.rotation_angle) * MOVE_SPEED;
		new_y = (data->player.player_y ) + sin(data->player.rotation_angle) * MOVE_SPEED;
		if (wall_collision(data, new_y, new_x))
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
}

void	player_pos(t_data *data)
{
	if (data->dir_keys[0] == RIGHT_ARROW || data->dir_mouse[0] == RIGHT_CLICK)
	{
		data->player.rotation_angle += ROTATION_SPEED;
		if (data->player.rotation_angle > 2 * M_PI)
			data->player.rotation_angle -= 2 * M_PI;
	}
	else if (data->dir_keys[0] == LEFT_ARROW || data->dir_mouse[0] == LEFT_CLICK)
	{
		data->player.rotation_angle -= ROTATION_SPEED;
		if (data->player.rotation_angle < 0)
			data->player.rotation_angle += 2 * M_PI;	
	}
	if (data->dir_keys[1] == A_LEFT)
		player_left_right(data, 0);
	else if (data->dir_keys[1] == D_RIGHT)
		player_left_right(data, 1);
	if (data->dir_keys[2] == W_UP || data->dir_mouse[1] == SCROLL_UP)
		player_up_down(data, 1);
	else if (data->dir_keys[2] == S_DOWN || data->dir_mouse[1] == SCROLL_DOWN)
		player_up_down(data, 0);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_msg("exit with esc key", 0);
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = key_code;
	else if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = key_code;
	else if (key_code == W_UP || key_code == S_DOWN )
		data->dir_keys[2] = key_code;
    return 0;
}

int handle_mouse_click(int button, int x, int y, t_data *data) 
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = button;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		data->dir_mouse[1] = button;
    return 0;
}

int release_mouse(int button, int x, int y, t_data *data) 
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = -1;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		data->dir_mouse[1] = -1;
    return 0;
}

int	key_code(t_data *data)
{
	// mlx_hook(data->win_ptr, 4, 4, handle_mouse_click, data);
	// mlx_hook(data->win_ptr, 5, 8, release_mouse, data);
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0,  key_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	player_pos(data);
	render_player(data);
	return (0);
}
