/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:22:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/18 19:33:59 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

// int wall_collision(t_data *data, double y, double x)
// {
//     int new_y = floor(((y)/ (TILE_SIZE)));
//     int new_x = floor(((x) / (TILE_SIZE)));

//     if (data->map->map[new_y][new_x] == '1')
//         return 0;
//     else
//         return 1;
// }

// void left_pos(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;
// 	int		is_wall;
// 	double	mv_i;

// 	mv_i = 1;
// 	is_wall = 0;
// 	while(mv_i < MOVE_SPEED)
// 	{
// 		new_x = data->player.player_x + cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
// 		new_y = data->player.player_y + sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
// 		if (!wall_collision(data, new_y, new_x))
// 		{
// 			is_wall = 1;
// 			break;
// 		}
// 		mv_i += 0.1;
// 	}
// 	if (!is_wall)
// 	{
// 		data->player.player_x = new_x;
// 		data->player.player_y = new_y;
// 	}
// }

// void right_pos(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;
// 	int		is_wall;
// 	double	mv_i;

// 	mv_i = 1;
// 	is_wall = 0;
// 	while(mv_i < MOVE_SPEED)
// 	{
// 		new_x = data->player.player_x - cos(data->player.rotation_angle  + M_PI / 2) * MOVE_SPEED;
// 		new_y = data->player.player_y - sin(data->player.rotation_angle + M_PI / 2) * MOVE_SPEED;
// 		if (!wall_collision(data, new_y, new_x))
// 		{
// 			is_wall = 1;
// 			break;
// 		}
// 		mv_i+=0.1;
// 	}
// 	if (!is_wall)
// 	{
// 		data->player.player_x = new_x;
// 		data->player.player_y = new_y;
// 	}	
// }

// void	player_left_right(t_data *data, int key)
// {
// 	double new_x;
// 	double new_y;
// 	int is_wall = 0;
// 	double mv_i;

// 	if (key == 0) // left
// 		left_pos(data);
// 	else if (key == 1) //right
// 		right_pos(data);
// }

// void up_pos(t_data *data)
// {
// 	double	new_y;
//     double	new_x;
// 	int is_wall = 0;
// 	double mv_i;
// 	mv_i = 1;
// 	is_wall = 0;
// 	while(mv_i < MOVE_SPEED)
// 	{
//     	new_x = data->player.player_x - cos(data->player.rotation_angle) * mv_i;
//     	new_y = data->player.player_y - sin(data->player.rotation_angle) * mv_i;
//     	if (!wall_collision(data, new_y, new_x))
//     	{
// 			is_wall = 1;
// 			break;
//     	}
//     	mv_i+=0.1;
// 	}
// 	if (!is_wall)
// 	{
// 		data->player.player_x = new_x;
//     	data->player.player_y = new_y;
// 	}
// }

// void down_up(t_data *data)
// {
// 	double	new_y;
//     double	new_x;
// 	int is_wall ;
// 	double mv_i;
	
// 	mv_i = 1;
// 	is_wall = 0;
// 	while(mv_i < MOVE_SPEED)
// 	{
//     	new_x = data->player.player_x + cos(data->player.rotation_angle) * mv_i;
//     	new_y = data->player.player_y + sin(data->player.rotation_angle) * mv_i;
//     	if (!wall_collision(data, new_y, new_x))
//     	{
// 			is_wall = 1;
// 			break;
//     	}
//     	mv_i+=0.1;
// 	}
// 	if (!is_wall)
// 	{
// 		data->player.player_x = new_x;
//     	data->player.player_y = new_y;
// 	}
// }

// void player_up_down(t_data *data, int key)
// {

// 	if (key == 1) // up
// 		up_pos(data);
// 	if (key == 0) // down
// 		down_up(data);
// }