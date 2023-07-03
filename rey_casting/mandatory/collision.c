/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:22:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 21:02:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"

int	wall_collision(t_data *data, double y, double x)
{
	int	x1[2];
	int	y1[2];

	y1[0] = ((y - 8) / TILE_SIZE);
	y1[1] = ((y + 8) / TILE_SIZE);
	x1[0] = ((x - 8) / TILE_SIZE);
	x1[1] = ((x + 8) / TILE_SIZE);
	if (y <= 0 || y >= data->map->height * TILE_SIZE || x <= 0
		|| x >= data->map->width * TILE_SIZE)
		return (0);
	else if (data->map->map[y1[0]][x1[0]] == '1')
		return (0);
	else if (data->map->map[y1[1]][x1[1]] == '1')
		return (0);
	else if (data->map->map[y1[0]][x1[1]] == '1')
		return (0);
	else if (data->map->map[y1[1]][x1[0]] == '1')
		return (0);
	else
		return (1);
}

int	key_release(int key_code, t_data *data)
{
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = -1;
	if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = -1;
	if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = -1;
	return (0);
}

void	get_directions(t_rey *rays, double angle)
{
	angle = normalize_angle(angle);
	rays->facing_up = 0;
	rays->facing_down = 0;
	rays->facing_left = 0;
	rays->facing_right = 0;
	rays->facing_down = ((angle > 0) && (angle < M_PI));
	rays->facing_up = !rays->facing_down;
	rays->facing_right = ((angle < 0.5 * M_PI) || (angle > 1.5 * M_PI));
	rays->facing_left = !rays->facing_right;
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

int	hit_wall(t_data *data, double y, double x)
{
	int	y1;
	int	x1;

	y1 = (y / TILE_SIZE);
	x1 = (x / TILE_SIZE);
	if (!data->map->map || !data->map->map[y1] || !data->map->map[y1][x1])
		return (0);
	if (y < 0 || y > data->map->height * TILE_SIZE || x < 0
		|| x > data->map->width * TILE_SIZE)
		return (0);
	if ((data->map->map[y1][x1] != '\0' && data->map->map[y1][x1] == '1'))
		return (0);
	return (1);
}
