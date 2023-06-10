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

void	read_map(t_data *data, char *s)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		data->map[index] = get_next_line(fd);
		if (data->map[index] == NULL)
			break ;
		index++;
	}
	close(fd);
}

t_data	*init_data(t_data *data, char *s)
{
	char	*line;
	int		fd;

	data = malloc(sizeof(t_data));
	data->height = 0;
	data->width = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (data->height == 0 && line == NULL)
			exit_msg("ERROR : \n map !! \n", 1);
		if (line == NULL)
			break ;
		data->width = ft_strlen(line);
		data->height++;
		free(line);
	}
	data->map = malloc((data->height + 1) * sizeof(char *));
	read_map(data, s);
	close(fd);
	return (data);
}


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	init_pos(t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map[j])
	{
		i  = 0;
		while(data->map[j][i])
		{
			if (data->map[j][i] == 'N')
			{
				data->player_x = j;
				data->player_y = i;
			}
			i++;
		}
		j++;
	}
}

void	rey_casting(t_map *map, char *argv)
{
	t_data	*data;
	    
	data = malloc(sizeof(t_data));
	data = init_data(data, argv);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "The_KM_game!");
	data->img = malloc(sizeof(t_img));
	data->img->img_ptr = mlx_new_image(data->mlx_ptr,WIDTH, HEIGHT);	
    data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	init_pos(data);
	draw_2d_map(data->img, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, key_code, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	mlx_loop(data->mlx_ptr);
}

