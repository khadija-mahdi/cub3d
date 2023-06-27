/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 07:06:56 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 22:00:10 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	init_player_directions(t_data *data, int y, int x)
{
	if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'W')
		data->player.rotation_angle = 0;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'E')
		data->player.rotation_angle = M_PI;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'N')
		data->player.rotation_angle = M_PI / 2;
	else if (data->map->map[(y / TILE_SIZE)][x / TILE_SIZE] == 'S')
		data->player.rotation_angle = 3 * M_PI / 2;
}

void	player_init(t_data *data)
{
	data->player.player_x = data->map->x * (TILE_SIZE) + (TILE_SIZE / 2);
	data->player.player_y = data->map->y * (TILE_SIZE) + (TILE_SIZE / 2);
	init_player_directions(data, data->player.player_y, data->player.player_x);
}

int	get_height_map(t_data *data)
{
	int	height;

	height = 0;
	while (data->map && data->map->map[height])
		height++;
	return (height);
}

int get_walls_nbr(t_data *data)
{
	int i  = 0;
	int j = 0;
	int walls_nbr;
	while (data->map->map && data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '1')
				walls_nbr++;
			j++;
		}
		i++;
	}
	return (walls_nbr);
}

t_mini_img *minimap_img(t_mini_img *mini_img, t_data *data)
{
	mini_img = malloc(sizeof(t_mini_img));
	mini_img->img_ptr = mlx_new_image(data->mlx_ptr, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	mini_img->addr = mlx_get_data_addr(mini_img->img_ptr, &mini_img->bits_per_pixel, &mini_img->line_length, &mini_img->endian);
	return (mini_img);
}

void	init_window_img(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->map)
		return ;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
		"The_KM_game!");
	data->mini_img = minimap_img(data->mini_img, data);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->line_length,
		&data->img->endian);
}

t_data	*init_data(t_data *data, struct s_map_info *map)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map;
	map->height = 0;
	data->wall_nbr = get_walls_nbr(data);
	map->height = get_height_map(data);
	init_window_img(data);
	data->rays = malloc(sizeof(t_rey *) * WIDTH);
	if (!data->rays)
		return (NULL);
	player_init(data);
	data->dir_keys[0] = -1;
	data->dir_keys[1] = -1;
	data->dir_keys[2] = -1;
	data->dir_mouse[0] = -1;
	data->dir_mouse[1] = -1;
	return (data);
}
