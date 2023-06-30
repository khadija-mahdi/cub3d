/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:47 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/30 04:34:12 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
				/ 8));
		*(unsigned int *)dst = color;
	}
}


void	render_player(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bits_per_pixel, &data->img->line_length,
		&data->img->endian);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
}

int	exit_program(int key_code)
{
	exit_msg("Exit the program with the X !!", 0);
	return (0);
}
