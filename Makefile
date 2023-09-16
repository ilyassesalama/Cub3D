# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 18:09:46 by isalama           #+#    #+#              #
#    Updated: 2023/09/16 21:16:53 by isidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# source code
HELPERS = helpers/class_helper.c helpers/class_getline.c \
	  	  helpers/class_parsing.c helpers/class_utils.c
DRAWERS = drawers/mlx_window.c drawers/mlx_map.c drawers/mlx_player.c
LIBFT = libft/strings_1.c libft/strings_2.c libft/strings_3.c \
		libft/strings_4.c
		
SRC = $(HELPERS) $(DRAWERS) $(LIBFT) cub3d.c
		

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
COMPILER = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -Imlx -lmlx -framework OpenGL -framework AppKit  $(OBJ) -o $(NAME)
	@clear

%.o: %.c cub3d.h
	$(COMPILER) $(FLAGS) -c $< -o $@
	@clear
clean:
	rm -rf $(OBJ)
	@clear

fclean: clean
	rm -rf $(NAME)
	@clear

re: fclean all