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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>

# include"libft/libft.h"

typedef struct stack
{
	int	*number;
	int	top;
	int	items;
} s_stack;

void	checkparams(int argc, char **argv);
void	swapitems(s_stack *stack, int top, int i);
void	ft_printexit(int n);

s_stack	*fillstack_a(int argc, char **argv);
s_stack	*fillstack_b(int argc);

void	sort3_1(s_stack *a);
void	sort3_2(s_stack *a);

void	swap(s_stack *stack, char c);
void	rotate(s_stack *stack, char c);
void	revrotate(s_stack *stack, char c);
void	push(s_stack *a, s_stack *b, int dir);
void	m_swap(s_stack *a, s_stack *b);
void	m_rotate(s_stack *a, s_stack *b);
void	m_revrotate(s_stack *a, s_stack *b);

#endif