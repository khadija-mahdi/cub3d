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

int	keys_down(int key_code,t_data *data)
{
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = -1;
	if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = -1;
	if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = -1;
    return 0;
}

void	game_running(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	mlx_loop_hook(data->mlx_ptr, key_code, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
void	rey_casting(struct s_map_info *map)
{
	t_data	*data;

	data = init_data(data, map);
	data->dir_keys[0] = -1; // l_arr r_arr 
	data->dir_keys[1] = -1; // left right
	data->dir_keys[2] = -1; // up down 
	draw_2d_map(data);
	game_running(data);
}

