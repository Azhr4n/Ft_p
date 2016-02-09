# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 15:30:43 by pivanovi          #+#    #+#              #
#    Updated: 2014/04/21 19:45:22 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVEUR =	src_serveur/loop_command.c				\
				src_serveur/check_error.c				\
				src_serveur/open_close.c				\
				src_serveur/serveur.c					\
				src_serveur/execs.c						\
				tools/ft_split.c						\
				tools/tools2.c							\
				tools/tools.c

SRC_CLIENT =	src_client/client.c						\
				tools/ft_split.c						\
				tools/tools2.c							\
				tools/tools.c

OBJ1 = $(SRC_SERVEUR:.c=.o)
OBJ2 = $(SRC_CLIENT:.c=.o)

CFLAGS += -I./includes

all: serveur client

serveur: $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $@

client: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $@

clean:
	/bin/rm -f $(OBJ1) && /bin/rm -f $(OBJ2)

fclean: clean
	/bin/rm -f serveur && /bin/rm -f client

re: fclean all
