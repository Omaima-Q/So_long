# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:32:19 by kafortin          #+#    #+#              #
#    Updated: 2024/11/12 20:30:55 by omaimaqaroo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

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
		@echo "Compiling Libft..."
		@ar rcs $(NAME) $(OBJS)
		@echo "Completed!"

clean:
		@echo "Cleaning all object files... 🧹"
		$(RM) $(OBJS)
		@echo "Completed!"
		
fclean: clean
		@echo "Cleaning library... 🧹"
		$(RM) $(NAME)
		@echo "✨ Cleaning complete! ✨"

re: fclean all

add:
	git add $(FILES)
	git add *.h
	git add Makefile

commit:
	git commit -m "$m"

push:
	git push github master

git: add commit push

.PHONY: all clean fclean re add commit push git