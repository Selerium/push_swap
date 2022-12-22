/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:58:11 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/22 19:25:19 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	m_swap(t_stack *a, t_stack *b)
{
	swap(a, 'a', 0);
	swap(b, 'b', 0);
	printf("ss\n");
	g_counter++;
}

void	m_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 'a', 0);
	rotate(b, 'b', 0);
	printf("rr\n");
	g_counter++;
}

void	m_revrotate(t_stack *a, t_stack *b)
{
	revrotate(a, 'a', 0);
	revrotate(b, 'a', 0);
	printf("rrr\n");
	g_counter++;
}

void	updatetop(t_stack *stack, int opt)
{
	if (opt == 0)
	{
		if (--(stack->top) < 0)
			stack->top += stack->items;
	}
	else if (opt == 1)
	{
		if (++(stack->top) >= stack->items)
			stack->top = 0;
	}
}

void	updateend(t_stack *stack, int opt)
{
	if (opt == 1)
	{
		if (--(stack->end) < 0)
			stack->end += stack->items;
	}
	else if (opt == 0)
	{
		if (++(stack->end) >= stack->items)
			stack->end = 0;
	}
}
