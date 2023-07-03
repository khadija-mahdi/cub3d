/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collisions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:47:08 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 22:22:16 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rey_casting_bonus.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	get_directions(t_rey *rays, double angle)
{
	angle = normalize_angle(angle);
	rays->facing_up = 0;
	rays->facing_down = 0;
	rays->facing_left = 0;
	rays->facing_right = 0;
	rays->facing_down = (angle > 0 && angle < M_PI);
	rays->facing_up = !rays->facing_down;
	rays->facing_right = (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	rays->facing_left = !rays->facing_right;
}

int	hit_wall(t_data *data, double y, double x)
{
	int	y1;
	int	x1;

	y1 = (y / TILE_SIZE);
	x1 = (x / TILE_SIZE);
	if (!data->map->map || !data->map->map[y1]
		|| !data->map->map[y1][x1])
		return (0);
	if (y < 0 || y > data->map->height * TILE_SIZE || x < 0
		|| x > data->map->width * TILE_SIZE)
		return (0);
	if ((data->map->map[y1][x1] != '\0'
		&& data->map->map[y1][x1] == '1'))
		return (0);
	return (1);
}

char	**new_mini_map(t_data *data)
{
	char	**new_map;
	int		i;
	int		j;

	j = data->map->y;
	i = 0;
	new_map = malloc(sizeof(char *) * data->map->height);
	while (data->map->map && data->map->map[j])
		new_map[i++] = ft_strdup(data->map->map[j++]);
	new_map[i] = 0;
	return (new_map);
}

void	render_mini_map(t_data *data)
{
	char	**new;

	new = data->map->map;
	data->scaler_hight = 0.25;
	data->scaler_width = 0.25;
	if ((data->map->height * TILE_SIZE) * 0.25 >= HEIGHT / 2
		|| (data->map->width * TILE_SIZE) * 0.25 >= WIDTH / 2)
	{
		data->scaler_width = 0.1;
		data->scaler_hight = 0.1;
	}
	if ((data->map->height * TILE_SIZE) * 0.25 >= HEIGHT
		|| (data->map->width * TILE_SIZE) * 0.25 >= WIDTH)
	{
		data->scaler_hight = 0.25;
		data->scaler_width = 0.25;
	}
	draw_walls(data, DARK_GREEN);
	draw_player(data);
}
