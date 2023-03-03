# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 19:36:44 by ablanco-          #+#    #+#              #
#    Updated: 2023/03/03 20:04:51 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		=	valid_map.c\
			utils.c\
			get_next_line.c\
			get_next_line_utils.c\
			main.c\
			save_map.c\
			window.c\
			images.c\
			move.c\
			put_nbr.c\

OBJS	= ${SRC:.c=.o}
LIB		= ./libft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address

RM		= rm -f

all:	${NAME} libft

${NAME}:	${OBJS}
			make -C $(LIB)
			$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB)/libft.a

exe:
	./$(NAME)

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}
		make -C $(LIB) clean

fclean: clean
		${RM} ${NAME}
		make -C $(LIB) fclean

re: fclean all

.PHONY: clean exe fclean re all