# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2023/06/28 15:37:09 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(filter-out thingsidontneed.c teststacks.c, $(wildcard *.c))

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	make bonus -C libft
	gcc $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

bonus:

all: $(NAME)

norm:
	python3 -m norminette $(SRCS) push_swap.h libft/*.c libft/libft.h

test: $(NAME)
	make
	/usr/bin/python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all