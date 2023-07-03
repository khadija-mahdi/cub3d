/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rey_Casting_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:58:20 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 21:09:41 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REY_CASTING_BONUS_H
# define REY_CASTING_BONUS_H

# include "../macros.h"
# include "../../cub3d.h"
# include "../../get_next_line/get_next_line.h"
# include "../../minilibft/minilibft.h"
# include "../../parser/parser.h"
# include "../reycasting.h"

void	draw_line(t_data *data, int y_start, int x_start);
void	draw_walls(t_data *data, int clr);
void	draw_player(t_data *data);
void	rey_casting_bonus(struct s_map_info *map);
int		handle_mouse_click(int button, int x, int y, t_data *data);
int		release_mouse(int button, int x, int y, t_data *data);
void	render_mini_map(t_data *data);
int		key_press_bonus(int key_code, t_data *data);
int		key_release_bonus(int key_code, t_data *data);
void	cast_rays_bonus(t_data *data);
void	defend_factor(t_data *data);

#endif
