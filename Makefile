# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:13:09 by dgioia            #+#    #+#              #
#    Updated: 2023/01/04 07:02:04 by dgioia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc -pthread

CFLAGS	=	

SRC	=	src/main.c \
		src/init.c \
		src/utils.c \
		src/thread.c \
		src/action.c \
		src/ft_free.c \

OBJ	=	$(SRC:.c=.o)

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re