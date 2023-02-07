# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 19:36:44 by ablanco-          #+#    #+#              #
#    Updated: 2023/02/06 19:10:36 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		=	valid_map.c\
			utils.c\
			get_next_line.c\
			get_next_line_utils.c\

OBJS	= ${SRC:.c=.o}


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx

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