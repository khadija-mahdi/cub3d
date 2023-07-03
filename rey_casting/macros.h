/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 03:26:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/02 20:53:53 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// window_size  --------------------------->

# define WIDTH 1800
# define HEIGHT 1000

// mouse buttons ---------------------------->

# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// objects size ---------------------------->
# define TILE_SIZE 64
# define M_TILE_SIZE 16
# define PLAYER_SIZE 8

// keys codes  ------------------------------>

# define ESC 53
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define UP_ARROW 126
# define S_DOWN 1
# define W_UP 13
# define A_LEFT 0
# define D_RIGHT 2

// player movement --------------------------->
# define MOVE_SPEED 7
# define ROTATION_SPEED 0.05

// press ; release code ----------------------->

# define ON_KEYDOWN 2
# define ON_KEYUP 3

// colors ----------------------------------->

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BEIGE 0xF5F5DC
# define RED 0xFF0000
# define LIGHT_GRAY 0xD3D3D3
# define PALE_BLUE 0xADD8E6
# define CREAM 0xFFFDD0
# define LIGHT_GREEN 0x90EE90
# define SOFT_PINK 0xFFC0CB
# define LIGHT_YELLOW 0xFFFFE0
# define LAVENDER 0xE6E6FA
# define PEACH 0xFFDAB9
# define LIGHT_BEIGE 0xF5F5DC
# define PALE_GRAY 0xECECEC
# define MINT_GREEN 0x98FF98
# define SOFT_YELLOW 0xFFFFD8
# define SKY_BLUE 0x87CEEB
# define PASTEL_PURPLE 0xE0BBE4
# define LIGHT_SALMON 0xFFA07A
# define WARM_GRAY 0xBEBEBE
# define SOFT_GREEN 0xC8E6C9
# define LIGHT_CORAL 0xF08080
# define LIGHT_BLUE 0xADD8E6
# define LIGHT_PURPLE 0xE6E6FA
# define LIGHT_PINK 0xFFB6C1
# define LIGHT_ORANGE 0xFFD700
# define LIGHT_BROWN 0xD2B48C
# define LIGHT_CYAN 0xE0FFFF
# define LIGHT_RED 0xFF6347
# define LIGHT_MAGENTA 0xFF00FF
# define LIGHT_LIME 0x00FF00
# define LIGHT_TEAL 0x008080
# define DARK_GRAY 0xA9A9A9
# define DARK_BLUE 0x00008B
# define DARK_GREEN 0x006400
# define DARK_RED 0x8B0000
# define DARK_PURPLE 0x800080
# define DARK_CYAN 0x008B8B
# define DARK_YELLOW 0xFFD700
# define DARK_ORANGE 0xFF8C00
# define DARK_BROWN 0x8B4513
# define DARK_PINK 0xFF1493

#endif