/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:00:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:26:40 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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
	t_map_info	data;

	data.args = argc;
	data.map_path = argv[1];
	check_path_errors(&data);
	check_map_and_texture_errors(&data);
	get_textures_path(&data);
	rey_casting(&data);
}

/* please ila kont baghi t9ed norm ana add it some variables to your struct,
, if you wanna merge just copy past please don't remove all the folder 'parser' thanks :)" */