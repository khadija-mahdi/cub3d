/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:45:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/18 19:33:41 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

int custom_round(double num) 
{
    int floor_value = floor(num);
    int ceil_value = ceil(num);

    if (num - floor_value >= 0.9)
        return ceil_value;
    else
        return floor_value;
}

int wall_collision(t_data *data, double y, double x)
{
    int new_y = floor(((y)/ (TILE_SIZE)));
    int new_x = floor(((x) / (TILE_SIZE)));

	// printf("c %c x : %f y %f\n",data->map->map[new_y][new_x], x, y);
    if (data->map->map[new_y][new_x] == '1')
        return 0;
    else
        return 1;
}

void	player_left_right(t_data *data, int key)
{
	double new_x;
	double new_y;
	int is_wall = 0;
	double mv_i;

	if (key == 0) // left
	{
		mv_i = 1;
		while(mv_i < MOVE_SPEED)
		{
			new_x = data->player.player_x + cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
			new_y = data->player.player_y + sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
	    	if (!wall_collision(data, new_y, new_x))
	    	{
				is_wall = 1;
				break;
	    	}
	    	mv_i+=0.1;
		}
		if (!is_wall)
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
	else if (key == 1) //right
	{
		mv_i = 1;
		while(mv_i < MOVE_SPEED)
		{
			new_x = data->player.player_x - cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
			new_y = data->player.player_y - sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
	    	if (!wall_collision(data, new_y, new_x))
	    	{
				is_wall = 1;
				break;
	    	}
	    	mv_i+=0.1;
		}
		if (!is_wall)
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
	int is_wall = 0;
	double mv_i;

	if (key == 1) // up
	{
		mv_i = 1;
		is_wall = 0;
		while(mv_i < MOVE_SPEED)
		{
	    	new_x = data->player.player_x - cos(data->player.rotation_angle) * mv_i;
	    	new_y = data->player.player_y - sin(data->player.rotation_angle) * mv_i;
	    	if (!wall_collision(data, new_y, new_x))
	    	{
				is_wall = 1;
				break;
	    	}
	    	mv_i+=0.1;
		}
		if (!is_wall)
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
	if (key == 0) // down
	{
		mv_i = 1;
		is_wall = 0;
		while(mv_i < MOVE_SPEED)
		{
	    	new_x = data->player.player_x + cos(data->player.rotation_angle) * mv_i;
	    	new_y = data->player.player_y + sin(data->player.rotation_angle) * mv_i;
	    	if (!wall_collision(data, new_y, new_x))
	    	{
				is_wall = 1;
				break;
	    	}
	    	mv_i+=0.1;
		}
		if (!is_wall)
		{
			data->player.player_x = new_x;
	    	data->player.player_y = new_y;
		}
	}
}
int	key_code(t_data *data)
{

	mlx_hook(data->win_ptr, 3, 1L << 0, keys_down, data);
	mlx_hook(data->win_ptr, 2, 1L << 1, keys_up, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	player_pos(data);
	render_player(data);
	return (0);
}

void	player_pos(t_data *data)
{
	if (data->dir_keys[0] == RIGHT_ARROW)
		data->player.rotation_angle += ROTATION_SPEED;
	else if (data->dir_keys[0] == LEFT_ARROW)
		data->player.rotation_angle -= ROTATION_SPEED;
	if (data->dir_keys[1] == A_LEFT)
		player_left_right(data, 0);
	else if (data->dir_keys[1] == D_RIGHT)
		player_left_right(data, 1);
	if (data->dir_keys[2] == W_UP)
		player_up_down(data, 1);
	else if (data->dir_keys[2] == S_DOWN)
		player_up_down(data, 0);
}

int	keys_up(int key_code, t_data *data)
{
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = key_code;
	else if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = key_code;
	else if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = key_code;
    return 0;
}
