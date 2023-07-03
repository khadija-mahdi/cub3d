/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:22:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 20:57:35 by kmahdi           ###   ########.fr       */
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
	if (y <= 0 || y >= (data->map->height * TILE_SIZE)
		|| x <= 0 || x >= (data->map->width * TILE_SIZE))
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

int	key_release_bonus(int key_code, t_data *data)
{
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = -1;
	if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = -1;
	if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = -1;
	return (0);
}
