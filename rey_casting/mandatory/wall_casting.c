/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:04:25 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/03 03:33:55 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"

void	cast_single_ray(t_data *data, float ray_angle, int index)
{
	get_directions(data->rays[index], ray_angle);
	horizontal_ray(data, data->rays[index], ray_angle);
	vertical_ray(data, data->rays[index], ray_angle);
	if (data->rays[index]->ver_ray.distance 
		< data->rays[index]->hor_ray.distance)
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
			my_mlx_pixel_put(data->img, i, half_hight, convert_color(data,
					data->map->ceiling_rgb));
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
			my_mlx_pixel_put(data->img, i, half_hight,
				convert_color(data, data->map->floor_rgb));
		half_hight++;
	}
}

void	cast_rays(t_data *data)
{
	double	ray_angle;
	double	hight_wall_hit;
	int		i;
	double	dpp;

	ray_angle = data->player.rotation_angle - (data->fov / 2);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i] = malloc(sizeof(t_rey));
		if (!data->rays[i])
			return ;
		cast_single_ray(data, ray_angle, i);
		data->rays[i]->distance = data->rays[i]->distance
			* cos(data->rays[i]->ray_angle - data->player.rotation_angle);
		dpp = (WIDTH / 2) / tan(data->fov);
		hight_wall_hit = (TILE_SIZE / data->rays[i]->distance) * dpp;
		draw_top_half_wall(i, hight_wall_hit, data, data->rays[i]);
		draw_bottom_half_wall(i, hight_wall_hit, data, data->rays[i]);
		ray_angle += (data->fov / WIDTH);
		free(data->rays[i]);
		i++;
	}
}
