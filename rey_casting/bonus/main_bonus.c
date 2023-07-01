/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:19:42 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/01 22:10:28 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rey_casting_bonus.h"

void	render_walls(t_data *data)
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

int	key_code_bonus(t_data *data)
{
	mlx_hook(data->win_ptr, 4, 1L<<4, handle_mouse_click, data);
	mlx_hook(data->win_ptr, 5, 1L<<3, release_mouse, data);
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press_bonus, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_release_bonus, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	render_position(data);
	render_walls(data);
	return (0);
}

void	running_game(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, key_code_bonus, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	rey_casting_bonus(struct s_map_info *map)
{
	t_data	*data;

	data = init_data(data, map);
	running_game(data);
}

int	main(int argc, char **argv)
{
	t_map_info	data;

	data.args = argc;
	data.map_path = argv[1];
	check_path_errors(&data);
	check_map_and_texture_errors(&data);
	rey_casting_bonus(&data);
}
