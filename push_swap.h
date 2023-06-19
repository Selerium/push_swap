/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:09:12 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/12 10:09:12 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///usr/bin/python3 python_visualizer.py `ruby -e "puts
//	(-50..50).to_a.shuffle.join(' ')"`

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>
# include"libft/libft.h"

int		g_counter;

typedef struct number
{
	int	value;
	int	position;
}	t_number;

typedef struct stack
{
	t_number	*numbers;
	int			top;
	int			end;
	int			items;
	int			chunk_size;
}	t_stack;

void	pushswap(t_stack *a, t_stack *b, int n);
void	test_stacks(t_stack *a, t_stack *b);

// stack 'n errors:
t_stack	*fillstack_a(int argc, char **argv);
t_stack	*fillstack_b(int argc);
void	ft_printexit(int n);

//checking parameters:
int		checknum(char *num);
int		checkword(char *num);
void	checkparams(int argc, char **argv);

// utilities:
void	swapitems(t_stack *stack, int top, int i);
int		complete(t_stack *a, int argc);
void	ft_freestacks(t_stack *a, t_stack *b);
void	test_stacks(t_stack *a, t_stack *b);

// wrappers:
void	ft_swap(t_stack *st, int i, int j);
void	sort3_1(t_stack *a, t_stack *b);
void	sort3_2(t_stack *a, t_stack *b);
void	check_swap(t_stack *a, t_stack *b);

// operations:
void	swap(t_stack *stack, char c, int opt);
void	rotate(t_stack *stack, char c, int opt);
void	revrotate(t_stack *stack, char c, int opt);
void	push(t_stack *a, t_stack *b, int dir);

// multi-stack operations:
void	m_swap(t_stack *a, t_stack *b);
void	m_rotate(t_stack *a, t_stack *b);
void	m_revrotate(t_stack *a, t_stack *b);
void	updatetop(t_stack *stack, int opt);
void	updateend(t_stack *stack, int opt);

//sorting:
int		find_median(t_stack *a);
void	sort_5(t_stack *a, t_stack *b, int n);
void	set_position(t_stack *a);

#endif