# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 19:36:44 by ablanco-          #+#    #+#              #
#    Updated: 2023/02/27 17:45:27 by ablanco-         ###   ########.fr        #
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

OBJS	= ${SRC:.c=.o}


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx -g -fsanitize=address

RM		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
			$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

exe:
	./$(NAME)

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: clean exe fclean re all