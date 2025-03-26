# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 01:19:13 by amzahir           #+#    #+#              #
#    Updated: 2025/03/26 03:09:53 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = server.o client.o utils.o

NAME = minitalk

DEP = minitalk.h

all : $(NAME)

%.o: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): server client

server: server.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf server client

re: fclean $(NAME)

.PHONY:
	all clean fclean re