# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frudello <frudello@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 16:00:17 by frudello          #+#    #+#              #
#    Updated: 2022/10/02 16:31:12 by frudello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	philo.c \
		events.c \
		routine.c \
		utils.c \
		utils2.c \
		utils3.c \
		utils4.c \

OBJS = ${SRC:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: clean fclean re bonus