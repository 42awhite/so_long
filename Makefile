# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 19:36:44 by ablanco-          #+#    #+#              #
#    Updated: 2023/01/11 19:36:47 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= valid_map.c

OBJS	= ${SRC:.c=.o}


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx

RM		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
			$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

exe:
	./$(NAME)

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all