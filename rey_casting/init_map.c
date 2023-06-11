/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 07:09:50 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/11 07:39:19 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	read_map(struct s_map *map, char *s)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		map->map[index] = get_next_line(fd);
		if (map->map[index] == NULL)
			break ;
		index++;
	}
	close(fd);
}

struct s_map	*init_map(struct s_map *map, char *s)
{
	char	*line;
	int		fd;

	map = malloc(sizeof(t_map));
	map->height = 0;
	map->width = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (map->height == 0 && line == NULL)
			exit_msg("ERROR : \n map !! \n", 1);
		if (line == NULL)
			break ;
		map->width = ft_strlen(line);
		map->height++;
		free(line);
	}
	map->map = malloc((map->height + 1) * sizeof(char *));
	read_map(map, s);
	close(fd);
	return (map);
}

void	init_pos(t_data *data)
{
	int i;
	int j;

	j = 0;
	while(data->map->map[j])
	{
		i  = 0;
		while(data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'N' || data->map->map[j][i] == 'S' || data->map->map[j][i] == 'E' || data->map->map[j][i] == 'W')
			{
				data->map->x = j;
				data->map->y = i;
			}
			i++;
		}
		j++;
	}
}