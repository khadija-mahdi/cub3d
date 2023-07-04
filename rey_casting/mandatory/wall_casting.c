/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:04:25 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/04 04:59:46 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"

void	cast_single_ray(t_data *data, float ray_angle, int index)
{
	data->rays[index]->is_vert = 0;
	data->rays[index]->is_hors = 0;
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
		data->rays[index]->is_vert = 1;
	}
	else
	{
		data->rays[index]->wall_x = data->rays[index]->hor_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->hor_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->hor_ray.distance;
		data->rays[index]->ray_angle = ray_angle;
		data->rays[index]->is_hors = 1;
	}
}

unsigned int	get_img_color(t_data *data, int offset_x, int offset_y)
{
	unsigned int	color;

	if (offset_x < 0 || offset_x >= TILE_SIZE || offset_y < 0
		|| offset_y >= TILE_SIZE)
		return (0);
	color = *(unsigned int *)(data->img_text->addr + (offset_y * data->img_text->line_length) + offset_x * (data->img_text->bits_per_pixel / 8));
	return (color);
}
void	draw_cube(t_data *data, int start_pos, int end_pos, int i, double ds)
{
	int index;
	unsigned int color;
	int offset_x;
	int offset_y;
	if (data->rays[i]->is_vert)
		offset_x = (int)data->rays[i]->wall_y % TILE_SIZE;
	else
		offset_x = (int)data->rays[i]->wall_x % TILE_SIZE;
	index = (HEIGHT / 2) - (ds / 2);
	while (index <= end_pos)
	{	offset_y = (index - start_pos) * ((double)TILE_SIZE / ds);
		color = get_img_color(data, offset_x, offset_y);
		my_mlx_pixel_put(data->img, i, index, color);
		index++;
	}
}

void	draw_3d_map(int i, double ds, t_data *data, t_rey *rays)
{
	double	index;
	int		start_pos;
	int		end_pos;

	start_pos = (HEIGHT / 2) - (ds / 2);
	end_pos = (HEIGHT / 2) + (ds / 2);
	index = 0;
	while (index < start_pos)
		my_mlx_pixel_put(data->img, i, index++, convert_color(data,
				data->map->ceiling_rgb));
	draw_cube(data, start_pos, end_pos, i, ds);
	index = end_pos;
	while (index > HEIGHT)
		my_mlx_pixel_put(data->img, i, index--,
			convert_color(data, data->map->floor_rgb));
}

void	cast_rays(t_data *data)
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
		free(data->rays[i]);
		i++;
	}
}
