# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stan <stan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 20:20:13 by stan              #+#    #+#              #
#    Updated: 2022/06/29 22:26:34 by stan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf

SRCS	= fdf.c

OBJS	= ${SRCS:.c=.o}

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
	$(CC) -Wall -Wextra -Werror -Iminilibx-linux -O3 -c $< -o $@

$(NAME): ${OBJS}
	$(CC) $(OBJS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f ${OBJS} ${Bonus_OBJS}

fclean:	clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
