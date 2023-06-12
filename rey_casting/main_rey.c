/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rey->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:26:27 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 18:06:53 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	game_running(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, key_code, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
void	rey_casting(struct s_map *map, char *argv)
{
	t_data	*data;

	map = init_map(map, argv);
	data = init_data(data, map);
	draw_2d_map(data);
	game_running(data);
}

