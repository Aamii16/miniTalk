# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 01:19:13 by amzahir           #+#    #+#              #
#    Updated: 2025/03/10 01:19:15 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
DEP = utils.c

NAME = minitalk

all : $(NAME)

$(NAME) := SERVER CLIENT

SERVER: server.o utils.o
	$(CC) $(CFLAGS) -o 

CLIENT:
	$(CC) $(CFLAGS) 

