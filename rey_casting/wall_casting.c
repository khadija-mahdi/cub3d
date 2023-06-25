/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/25 02:21:05 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void get_directions(t_rey *rays, double angle)
{
	angle =  normalize_angle(angle);
	rays->facing_up = 0;
	rays->facing_down = 0;
	rays->facing_left = 0;
	rays->facing_right = 0; 
	rays->facing_down = angle > 0 && angle < M_PI;
	rays->facing_up  = !rays->facing_down ;
	rays->facing_right = angle < 0.5 * M_PI  || angle > 1.5 *  M_PI ;
	rays->facing_left = !rays->facing_right;
}

double normalize_angle(double angle)
{
	angle = remainder(angle,  (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI );
	return (angle);
}

int hit_wall(t_data *data, double y, double x)
{
    if (data->map->map[(int)floor((y)/ TILE_SIZE)]
		[(int)floor((x)/ TILE_SIZE)] == '1')
        return (0);
    return (1);
}

void	cast_single_ray(t_data *data, float ray_angle, int index)
{
	get_directions(data->rays[index], ray_angle);
	horizontal_ray(data, data->rays[index], ray_angle);
	vertical_ray(data, data->rays[index], ray_angle);
	if (data->rays[index]->ver_ray.distance < data->rays[index]->hor_ray.distance) 
	{
		data->rays[index]->wall_x = data->rays[index]->ver_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->ver_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->ver_ray.distance;
	}
	else
	{	
		data->rays[index]->wall_x = data->rays[index]->hor_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->hor_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->hor_ray.distance;
	}
}

void	cast_rays(t_data *data)
{
	double	ray_angle;
	int		i;

	ray_angle = data->player.rotation_angle - (FOV / 2);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i] = malloc(sizeof(t_rey));
		cast_single_ray(data, ray_angle, i);
		draw_line(data, data->player.player_y, data->player.player_x,
			data->rays[i]->wall_y, data->rays[i]->wall_x, 0xFFF000);
		ray_angle += (FOV / WIDTH);
		free(data->rays[i]);
		i++;
	}
}
