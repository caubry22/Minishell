# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caubry <caubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:44:32 by caubry            #+#    #+#              #
#    Updated: 2022/09/12 15:01:58 by caubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror
NAME = minishell

SRC =	minishell.c \
		ft_split.c \
		ft_strcmp.c \
		ft_lstnew.c \
		ft_strdup.c \
		ft_lstadd_back.c
      
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)


.c.o:
	$(CC) ${CFLAGS} -I/usr/include  -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
