# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:41:54 by oqaroot           #+#    #+#              #
#    Updated: 2024/11/16 16:42:00 by oqaroot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

FILES = ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_itoa.c \
		ft_gnl.c \
		
OBJS = $(FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\033[0;31mCompiling Libft...pls wait\033[1;0m"
		@ar rcs $(NAME) $(OBJS)
		@echo "\033[1;33mCompleted! ✅\033[1;0m"

clean:
		@echo "\033[0;31mCleaning all object files... 🧹\033[1;0m"
		$(RM) $(OBJS)
		@echo "\033[0;33mCompleted! ✅\033[1;0m"
		
fclean: clean
		@echo "\033[0;36mCleaning library... 🧹\033[1;0m"
		$(RM) $(NAME)
		@echo "\033[0;32m✨ Cleaning complete! ✨\033[1;0m"

re: fclean all

.PHONY: all clean fclean re