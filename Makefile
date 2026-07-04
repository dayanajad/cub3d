# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 10:00:00 by bpichyal          #+#    #+#              #
#    Updated: 2026/06/21 22:10:06 by dbinti-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;92m
BLUE	= \033[0;94m
YELLOW	= \033[0;93m
RED		= \033[0;91m
RESET	= \033[0m

NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I. -Iinclude -Ilibft/libft -Ilibft/get_next_line -Iminilibx-linux

LIBFT_DIR := libft/libft
PRINTF_DIR := libft/Printf
MLX_DIR := minilibx-linux

LIBFT := $(LIBFT_DIR)/libft.a
PRINTF := $(PRINTF_DIR)/libftprintf.a

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRC_CORE := \
	src/main.c \
	src/error.c \
	src/init/init.c \
	src/init/app_loop.c \
	src/init/cleanup.c \
	src/map/input.c \
	src/map/map_fill.c \
	src/map/map_utils.c \
	src/map/map_validate.c \
	src/map/math_utils.c \
	src/map/move.c \
	src/parsing/parse.c \
	src/parsing/parse_colors.c \
	src/parsing/parse_elements.c \
	src/parsing/parse_map.c \
	src/parsing/parse_utils.c \
	src/render/raycast.c \
	src/render/raycast_draw.c \
	src/render/render.c \
	src/render/render_utils.c \
	src/render/tex.c \
	src/utils/time.c \
	src/utils/utils.c \
	libft/get_next_line/get_next_line.c \
	libft/get_next_line/get_next_line_utils.c

OBJ_DIR := obj
SRCS := $(SRC_CORE)

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX_DIR)/libmlx.a $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) is ready!$(RESET)"

$(LIBFT):
	@echo "$(BLUE)↪ Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@echo "$(BLUE)↪ Building Printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE)↪ Building MinilibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)  Compiling:$(RESET) $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory || true
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@rm -rf obj

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

bonus:
	@$(MAKE) BONUS=1 --no-print-directory

.PHONY: all clean fclean re bonus
