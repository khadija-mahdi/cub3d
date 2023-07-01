/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rey_Casting_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:58:20 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/01 22:06:57 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REY_CASTING_BONUS_H
# define REY_CASTING_BONUS_H

# include "../../cub3d.h"
# include "../../rey_casting//macros.h"
# include "../../minilibft/minilibft.h"
# include "../../get_next_line/get_next_line.h"
#include "../../parser/parser.h"
# include "../reycasting.h"

void					free_list(void **list);
void					exit_msg(char *msg, int status);
int						exit_program(int key_code);
t_data					*init_data(t_data *data, struct s_map_info *map);
int						key_code_fun(int key_code, t_data *data);
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
void					draw_2d_map(t_data *data);
void					rey_casting(struct s_map_info *map);
void					render_player(t_data *data);
int						key_code(t_data *data);
int						key_press(int key_code, t_data *data);
int						key_release(int key_code, t_data *data);
void					player_pos(t_data *data);
void					player_up_down(t_data *data, int key);
void					player_left_right(t_data *data, int key);
int						right_player(t_data *data);
int						down_player(t_data *data);
int						up_player(t_data *data);
int						left_player(t_data *data);
int						wall_collision(t_data *data, double y, double x);
void					cast_rays(t_data *data);
double					normalize_angle(double angle);
void					vertical_ray(t_data *data, t_rey *rays, double angle);
void					horizontal_ray(t_data *data, t_rey *rays, double angle);
int						hit_wall(t_data *data, double y, double x);
void					get_directions(t_rey *rays, double angle);
void					cast_single_ray(t_data *data, float ray_angle, int index);
void					draw_top_half_wall(int i, double ds, t_data *data, t_rey *rays);
void					draw_line(t_data *data, int y_start, int x_start, int end_y, int end_x, int clr);
void					draw_walls(t_data *data, int clr);
void					draw_player(t_data *data);
void					rey_casting_bonus(struct s_map_info *map);
void					draw_mini_map(t_data *data);
int						handle_mouse_click(int button, int x, int y, t_data *data);
int						release_mouse(int button, int x, int y, t_data *data);
void					render_mini_map(t_data *data);
int						key_press_bonus(int key_code, t_data *data);
int						key_release_bonus(int key_code, t_data *data);
void					cast_rays_bonus(t_data *data);

#endif