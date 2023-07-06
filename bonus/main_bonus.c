/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:19:42 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:09:30 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	cast_rays_bonus(data);
	render_mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
}

int	loop_hook(t_data *data)
{
	mlx_hook(data->win_ptr, 4, 1L << 4, handle_mouse_click, data);
	mlx_hook(data->win_ptr, 5, 1L << 3, release_mouse, data);
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	render_position(data);
	render(data);
	return (0);
}

void	start_the_game(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	get_textures_path(t_map_info *data)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	data->textures_path = malloc(sizeof(char *) * 4);
	while (data->textures && data->textures[i])
	{
		j = 0;
		while (data->textures[i][j])
		{
			if (data->textures[i][j] == '.')
			{
				data->textures_path[x++] = ft_substr(data->textures[i], j,
						ft_strlen(data->textures[i]));
				break ;
			}
			j++;
		}
		i++;
	}
	data->textures_path[x++] = NULL;
	free_list(data->textures);
}

int	main(int argc, char **argv)
{
	t_map_info	map;
	t_data		*data;

	map.args = argc;
	map.map_path = argv[1];
	check_path_errors(&map);
	check_map_and_texture_errors(&map);
	get_textures_path(&map);
	data = init_data(data, &map);
	start_the_game(data);
}
