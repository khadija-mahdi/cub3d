/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/10 03:06:26 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	count_map_lines(t_map_info *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_msg("Error\nThe map is empty\n", 1);
	data->map_lines_num = -6;
	if (is_whitespace(line) == 1)
		data->map_lines_num++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && is_whitespace(line) == 1)
			data->map_lines_num++;
	}
	close(fd);
}

void	read_and_check_map(char **line, t_map_info *data, int fd)
{
	int		i;
	char	*dup_line;

	i = 0;
	data->width = 0;
	data->util_map = malloc(sizeof(char *) * (data->map_lines_num + 1));
	while (is_whitespace(*line) == 0)
	{
		free(*line);
		*line = get_next_line(fd);
	}
	while (i < data->map_lines_num)
	{
		dup_line = ft_strdup(*line);
		data->util_map[i++] = str_space_trim(dup_line);
		free(*line);
		*line = get_next_line(fd);
		if (i < data->map_lines_num && is_whitespace(*line) == 0)
			exit_msg("Error\n", 1);
		free(dup_line);
	}
	data->util_map[i] = NULL;
	read_and_check_map_util(data);
	if (*line)
		free(*line);
}

void	check_map_walls(t_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_lines_num)
	{
		j = 0;
		while (j < ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == '0')
			{
				if ((j == 0) || (j == (ft_strlen(data->map[i]) - 1)) || \
					(i == 0) || (i == (data->map_lines_num - 1)) || \
					(is_valid_character(data->map[i][j - 1])) || \
					(is_valid_character(data->map[i][j + 1])) || \
					(is_valid_character(data->map[i - 1][j])) || \
					(is_valid_character(data->map[i + 1][j])))
					exit_msg("Error\nThe map is not closed\n", 1);
			}
			j++;
		}
		i++;
	}
}

void	check_map_characters(t_map_info *data)
{
	int	i;
	int	j;
	int	player_start_position;

	i = 0;
	player_start_position = 0;
	while (i < data->map_lines_num)
	{
		j = 0;
		while (j < ft_strlen(data->map[i]))
		{
			if (is_valid_character(data->map[i][j]) && data->map[i][j] != ' ')
				exit_msg("Error\nUnexpected character found in the map\n", 1);
			else if (is_valid_player_position(data->map[i][j]) == 0)
				player_start_position += check_player_position(&i, &j, data);
			j++;
		}
		i++;
	}
	if (!player_start_position)
		exit_msg("Error\nThe Player start position not found\n", 1);
	else if (player_start_position > 1)
		exit_msg("Error\nDuplicate player found\n", 1);
}

int	check_player_position(int *i, int *j, t_map_info *data)
{
	if (((*j) == 0) || ((*j) == (ft_strlen(data->map[(*i)]) - 1)) || \
		((*i) == 0) || ((*i) == (data->map_lines_num - 1)) || \
		(is_valid_character(data->map[(*i)][(*j) - 1])) || \
		(is_valid_character(data->map[(*i)][(*j) + 1])) || \
		(is_valid_character(data->map[(*i) - 1][(*j)])) || \
		(is_valid_character(data->map[(*i) + 1][(*j)])))
		exit_msg("Error\n", 1);
	data->x = (*j);
	data->y = (*i);
	return (1);
}
