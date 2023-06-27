/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 22:58:25 by kmahdi           ###   ########.fr       */
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
	return (angle);
}

int hit_wall(t_data *data, double y, double x)
{
	if (!data->map->map && !data->map->map[(int)(floor(y/ TILE_SIZE))] 
		&& !data->map->map[(int)(floor(y/ TILE_SIZE))][(int)(floor(x/ TILE_SIZE))])
		return (0);
	if (y <= 0 || y >= HEIGHT || x <= 0 || x >= WIDTH)
		return (0);
    if ((data->map->map[(int)(floor(y/ TILE_SIZE))]
		[(int)(floor(x/ TILE_SIZE))]) == '1')
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
		data->rays[index]->ray_angle = ray_angle;
	}
	else
	{	
		data->rays[index]->wall_x = data->rays[index]->hor_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->hor_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->hor_ray.distance;
		data->rays[index]->ray_angle = ray_angle;
	}
}

void	draw_top_half_wall(int i, double ds, t_data *data, t_rey *rays)
{
	double	half_hight;

	half_hight = (HEIGHT / 2);
	while (half_hight > 0)
	{
		if (half_hight > ((HEIGHT / 2) - ds))
			my_mlx_pixel_put(data->img, i, half_hight, 0Xffffff);
		else
			my_mlx_pixel_put(data->img, i, half_hight, 0X0000ff);
		half_hight--;
	}
}

void	draw_bottom_half_wall(int i, double ds, t_data *data, t_rey *rays)
{
	double	half_hight;

	half_hight = (HEIGHT / 2);
	while (half_hight < HEIGHT)
	{
		if (half_hight < ((HEIGHT / 2) + ds))
			my_mlx_pixel_put(data->img, i, half_hight, 0Xffffff);
		else
			my_mlx_pixel_put(data->img, i, half_hight, 0X00ff00);
		half_hight++;
	}
}

void	cast_rays(t_data *data)
{
	double	ray_angle;
	double	hight_wall_hit;
	int		i;

	ray_angle = data->player.rotation_angle - (FOV / 2);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i] = malloc(sizeof(t_rey));
		if (!data->rays[i])
			return ;
		cast_single_ray(data, ray_angle, i);
		data->rays[i]->distance = data->rays[i]->distance * cos(data->rays[i]->ray_angle - data->player.rotation_angle);
		double dpp = (WIDTH / 2) / tan(FOV / 2);
		hight_wall_hit = (TILE_SIZE / data->rays[i]->distance) * dpp;
		draw_top_half_wall(i, hight_wall_hit, data, data->rays[i]);
		draw_bottom_half_wall(i, hight_wall_hit, data, data->rays[i]);
		ray_angle += (FOV / WIDTH);
		free(data->rays[i]);
		i++;
	}
}
