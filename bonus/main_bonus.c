/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:19:42 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 22:32:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render(t_data *data)
{
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	cast_rays(data);
	render_mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
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

int	main(int argc, char **argv)
{
	t_map_info	map;
	t_data		*data;

	data = NULL;
	map.args = argc;
	map.map_path = argv[1];
	check_path_errors(&map);
	check_map_and_texture_errors(&map);
	get_textures_path(&map);
	data = init_data(data, &map);
	start_the_game(data);
}
