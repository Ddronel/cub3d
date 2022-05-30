# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:45:23 by eveiled           #+#    #+#              #
#    Updated: 2022/05/24 19:28:51 by jcollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
#
SOURSE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		check_and_parse/check_file.c check_and_parse/messages.c check_and_parse/parse_param.c check_and_parse/check_param.c check_and_parse/parse_check_map.c main.c\
		record_start_pos.c drawing/draw_utils.c drawing/draw_walls.c drawing/utils.c calculations.c manipulation.c
# 
CFLAGS	=  -I $(HEADER)
HEADER	= cub3d.h
HEADER_2 = get_next_line/get_next_line.h
OBJ = $(SOURSE:%.c=%.o)
LIBFTDIR = ./libft
LIBFT = -L./libft -lft
MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
CC = gcc
#
.PHONY : all clean fclean re bonus
#
all : $(NAME)
#
$(NAME) : $(OBJ) $(HEADER) $(HEADER_2)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
	@make clean -C $(LIBFTDIR)
#
fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
#
re_libft :
	@make re -C $(LIBFTDIR)
#
re : fclean all



