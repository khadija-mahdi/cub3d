# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/07/04 01:40:48 by kmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

SRC = main.c\
	./rey_casting/mandatory/main_rey.c\
	./rey_casting/mandatory/draw.c\
	./rey_casting/mandatory/player_movement.c\
	./rey_casting/mandatory/collision.c\
	./rey_casting/mandatory/wall_casting.c\
	./rey_casting/mandatory/move_directions.c\
	./get_next_line/get_next_line.c \
	./parser/parse_colors.c \
	./parser/parse_map.c \
	./parser/parse_path_and_map.c \
	./parser/parse_texture_utils.c \
	./parser/parser_utils.c \
	./parser/parse_texture.c \
	./rey_casting/utils.c\
	./rey_casting/vertical_rays.c\
	./rey_casting/horizontal_rays.c\
	./rey_casting/init.c\
	./rey_casting/textures.c\

BONUS_SRS = ./rey_casting/bonus/mini_map_bonus.c\
			./rey_casting/bonus/main_bonus.c\
			./rey_casting/bonus/collision_bonus.c\
			./rey_casting/bonus/draw_bonus.c\
			./rey_casting/bonus/player_movement_bonus.c\
			./rey_casting/bonus/wall_casting_bonus.c\
			./rey_casting/bonus/wall_collisions_bonus.c\
			./get_next_line/get_next_line.c \
			./parser/parse_colors.c \
			./parser/parse_map.c \
			./parser/parse_path_and_map.c \
			./parser/parse_texture_utils.c \
			./parser/parser_utils.c \
			./parser/parse_texture.c \
			./rey_casting/utils.c\
			./rey_casting/vertical_rays.c\
			./rey_casting/horizontal_rays.c\
			./rey_casting/init.c\


OBJ_DIR = files_objects
OBJ_DIR_BONUS = files_objects_bonus


OBJ= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

OBJ_BONUS= $(patsubst %.c,$(OBJ_DIR_BONUS)/%.o,$(BONUS_SRS))


CC = cc

# CFLAGS=  -Wall -Wextra -Werror 

MLX= -lmlx -framework OpenGL -framework AppKit

# DIB= -fsanitize=address -g3

$(RM) = rm -f 
  
all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJ) $(DIB) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJ_BONUS) $(DIB) -o $(NAME_BONUS)

bonus: $(NAME_BONUS) $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR_BONUS)
	make clean -C minilibft

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR_BONUS)
	make fclean -C minilibft

re: fclean bonus

