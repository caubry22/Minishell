# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caubry <caubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:44:32 by caubry            #+#    #+#              #
#    Updated: 2022/09/14 12:07:59 by caubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = minishell

SRC =	minishell.c \
		ft_cmdsplit.c \
		ft_split.c \
		ft_strcmp.c \
		ft_lstnew.c \
		ft_strdup.c \
		ft_lstadd_back.c \
		ft_lenmot.c \
		ft_nbtoken.c \
		ft_free.c \
		ft_builtin.c
      
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
