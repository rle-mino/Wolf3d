# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 21:53:13 by rle-mino          #+#    #+#              #
#    Updated: 2016/05/26 22:23:24 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=			Wolf3d

SRC			=			check_map.c				\
						color.c					\
						draw.c					\
						get.c					\
						hook.c					\
						main.c					\
						maps.c					\
						mouse_hook.c			\
						select_hook.c			\
						start_wolf.c			\
						strafe_hook.c			\
						ray_cast.c				\
						wolf_error.c			\
						wolf_init.c				\

OBJ_PATH	=			obj/

OBJ_NAME	=			$(SRC:.c=.o)
OBJ			=			$(addprefix $(OBJ_PATH),$(OBJ_NAME))
FLAGS		=			-Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
		make -C libft
		make -C libft/printf
		gcc -o $(NAME) $(FLAGS) -lmlx $^ -lft -L ./libft -lftprintf -L ./libft/printf -I includes -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p obj
	gcc $(FLAGS) -I includes -c $< -o $@

clean:
	make -C libft/ fclean
	make -C libft/printf/ fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
