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

typedef struct stack
{
	int	*number;
	int	top;
	int	end;
	int	items;
}	t_stack;

void	pushswap(t_stack *a, t_stack *b, int n);

// stack construction:
t_stack	*fillstack_a(int argc, char **argv);
t_stack	*fillstack_b(int argc);

// utilities:
void	checkparams(int argc, char **argv);
void	swapitems(t_stack *stack, int top, int i);
void	ft_printexit(int n);
void	test_stacks(t_stack *a, t_stack *b);
void	ft_swap(t_stack *st, int i, int j);
int		ft_median(t_stack *a);
void	updatetop(t_stack *stack, int opt);
void	updateend(t_stack *stack, int opt);
int		complete(t_stack *a, int argc);

// wrappers:
void	sort3_1(t_stack *a);
void	sort3_2(t_stack *a);
void	sort4(t_stack *a, t_stack *b, int n);
void	generalsort(t_stack *a, t_stack *b, int n);
void	testsort(t_stack *a, t_stack *b, int n, int opt);
int		middle(t_stack *a, int n);
void	boopbeep(t_stack *a, t_stack *b, int n, int opt);
void	beepboop(t_stack *a, t_stack *b, int n, int opt);

// operations:
void	swap(t_stack *stack, char c, int opt);
void	rotate(t_stack *stack, char c, int opt);
void	revrotate(t_stack *stack, char c, int opt);
void	push(t_stack *a, t_stack *b, int dir);

// multi-stack operations:
void	m_swap(t_stack *a, t_stack *b);
void	m_rotate(t_stack *a, t_stack *b);
void	m_revrotate(t_stack *a, t_stack *b);

#endif