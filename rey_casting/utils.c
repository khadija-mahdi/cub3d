/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:59:00 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 18:53:51 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	exit_msg(char *msg, int status)
{
	printf("%s", msg);
	exit(status);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

int	exit_program(int key_code)
{
	exit_msg("Exit the program with the X !!", 0);
	return (0);
}

void rendring(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr , data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,WIDTH, HEIGHT);	
    data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_2d_map(data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

int	key_code(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_msg("Exit the program with the 'ESC'  button !", 0);
	if (key_code == UP)
	{
		data->player_x -= 1;
		printf("x = %d y = %d\n", data->player_x, data->player_y);
		rendring(data);
	}
	else if (key_code == DOWN)
	{
		data->player_x += 1;
		rendring(data);
	}
	else if (key_code == RIGHT)
	{
		data->player_y += 1;
		rendring(data);
		
	}
	else if (key_code == LEFT)
	{
		data->player_y -= 1;
		rendring(data);
	}
	return (0);
}
