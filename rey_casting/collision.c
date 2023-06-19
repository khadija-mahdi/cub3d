/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:22:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/19 10:07:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

int wall_collision(t_data *data, double y, double x)
{
    if (data->map->map[(int)((y - 8)/ TILE_SIZE)][(int)((x - 8)/ TILE_SIZE)] == '1')
        return 0;
    else if (data->map->map[(int)((y + 8)/ TILE_SIZE)][(int)((x + 8)/ TILE_SIZE)] == '1')
        return 0;
	else if (data->map->map[(int)((y - 8)/ TILE_SIZE)][(int)((x + 8)/ TILE_SIZE)] == '1')
        return 0;
	else if (data->map->map[(int)((y + 8)/ TILE_SIZE)][(int)((x - 8)/ TILE_SIZE)] == '1')
        return 0;
    else
        return 1;
}
