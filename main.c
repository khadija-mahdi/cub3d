/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:00:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/27 18:01:37 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_map(char **map)
{
	for (int i = 0; map[i] != NULL; i++)
	{
		printf("%s \n", map[i]);
	}
}

int	main(int argc, char **argv)
{
	t_map_info	data;

	data.args = argc;
	data.map_path = argv[1];
	check_path_errors(&data);
	check_map_and_texture_errors(&data);
	printf_map(data.map);
	rey_casting(&data);
}
