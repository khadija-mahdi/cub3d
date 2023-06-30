/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:19:42 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/30 05:37:28 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

int	handle_mouse_click(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = button;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		data->dir_mouse[1] = button;
	return (0);
}

int	release_mouse(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = -1;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		data->dir_mouse[1] = -1;
	return (0);
}

void	render_mini_map(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->line_length,
		&data->img->endian);
	cast_rays(data);
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
}

int	key_code_bonus(t_data *data)
{
	mlx_hook(data->win_ptr, 4, 1L<<4, handle_mouse_click, data);
	mlx_hook(data->win_ptr, 5, 1L<<3, release_mouse, data);
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	player_pos(data);
	render_player(data);
	render_mini_map(data);
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
