/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 18:55:56 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H

# include "../cub3d.h"

# define BLOCK_SIZE 65

# define WIDTH 1300
# define HEIGHT 800

# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define ESC 53

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				width;
	int				height;	
	int				player_x;
	int				player_y;
	t_img 			*img;

}				t_data;


char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	free_list(char **list);
void	exit_msg(char *msg, int status);
int		exit_program(int key_code);
int		key_code(int key_code, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_2d_map(t_img *img, t_data *data);
// void	draw_wall(t_img *img, int i, int j);
void	draw_player(t_img *img, int i, int j);


#endif