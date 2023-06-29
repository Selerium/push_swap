# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2023/06/29 14:19:48 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(filter-out thingsidontneed.c teststacks.c, $(wildcard *.c))

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

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

1: $(NAME)
	make
	./push_swap -1

3: $(NAME)
	make
	/usr/bin/python3 python_visualizer.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`

5: $(NAME)
	make
	/usr/bin/python3 python_visualizer.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`

100: $(NAME)
	make
	/usr/bin/python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

500: $(NAME)
	make
	/usr/bin/python3 python_visualizer.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

errors: $(NAME)
	-./push_swap "1 4 2 a 2"
	-./push_swap 1 4 2 a 2
	-./push_swap "1a2"
	-./push_swap 1a2
	-./push_swap 1 2 3 4 3000000000
	-./push_swap "1 2 3 4 3000000000"

valgrind: $(NAME)
	make
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 4 3 2 1
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 2 3 4 5 6
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	sleep 5
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all