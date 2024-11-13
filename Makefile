# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:44:21 by omaimaqaroo       #+#    #+#              #
#    Updated: 2024/11/13 14:50:09 by omaimaqaroo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=address -g3

NAME = so_long

MAKE_LIBFT = cd ./Libft/ && make

MAKE_MLX = cd ./Minilibx/ && make

BONUS_NAME = so_long_bonus

FILES = ./srcs/end_game_options.c \
		./srcs/exit_management.c \
		./srcs/flood_fill.c \
		./srcs/init.c \
		./srcs/moves_utils.c \
		./srcs/moves.c \
		./srcs/put_images.c \
		./srcs/read_map.c \
		./srcs/so_long.c \
		./srcs/validate_map.c \

BONUS_FILES = 	./srcs/bonus/end_game_options_bonus.c \
				./srcs/bonus/ennemy_bonus.c \
				./srcs/bonus/exit_management_bonus.c \
				./srcs/bonus/flood_fill_bonus.c \
				./srcs/bonus/init_bonus.c \
				./srcs/bonus/moves_bonus.c \
				./srcs/bonus/moves_utils_bonus.c \
				./srcs/bonus/put_images_bonus.c \
				./srcs/bonus/read_map_bonus.c \
				./srcs/bonus/so_long_bonus.c \
				./srcs/bonus/utils_bonus.c \
				./srcs/bonus/validate_map_bonus.c \

OBJS = $(FILES:.c=.o)

BONUS_OBJS = $(BONUS_FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS) $(BONUS_OBJS) $(MAKE_MLX)

all: $(NAME)
		
$(NAME): $(OBJS)
		@$(MAKE_LIBFT)
		@$(MAKE_MLX)
		@echo "Compiling so_long..."
		@$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a ./Minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Completed! 🤠"
		
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
		@$(MAKE_LIBFT)
		@$(MAKE_MLX)
		@echo "Compiling bonus..."
		@$(CC) $(CFLAGS) $(BONUS_OBJS) ./Libft/libft.a ./Minilibx/libmlx.a -framework OpenGL -framework AppKit -o $(BONUS_NAME)
		@echo "Completed! 🤠"
		
clean:
		@$(MAKE) clean -C ./Libft
		$(RM) $(BONUS_OBJS)
		$(RM) $(OBJS)
		
fclean: 
		@$(MAKE) fclean -C ./Libft
		@$(MAKE) clean -C ./Minilibx
		$(RM) $(OBJS)
		$(RM) $(BONUS_OBJS)
		$(RM) $(NAME)
		$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re