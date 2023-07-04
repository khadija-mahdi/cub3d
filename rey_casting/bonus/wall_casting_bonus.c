/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/04 01:24:18 by kmahdi           ###   ########.fr       */
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

void	draw_3d_map(int i, double ds, t_data *data, t_rey *rays)
{
	double	index;

	index = 0;
	while (index < HEIGHT)
	{
		if (index < ((HEIGHT / 2) - (ds / 2)))
			my_mlx_pixel_put(data->img, i, index, convert_color(data,
					data->map->ceiling_rgb));
		else if (index > ((HEIGHT / 2) + (ds / 2)))
			my_mlx_pixel_put(data->img, i, index,
				convert_color(data, data->map->floor_rgb));
		else
			my_mlx_pixel_put(data->img, i, index, DARK_BLUE);
		index++;
	}
}

void	cast_rays_bonus(t_data *data)
{
	double	ray_angle;
	double	hight_wall_hit;
	int		i;
	double	camera_len;

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
		camera_len = (WIDTH / 2) / tan(data->fov / 2);
		hight_wall_hit = (TILE_SIZE / data->rays[i]->distance) * camera_len;
		draw_3d_map(i, hight_wall_hit, data, data->rays[i]);
		ray_angle += (data->fov / WIDTH);
		i++;
	}
}
