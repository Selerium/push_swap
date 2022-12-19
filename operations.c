/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:17:51 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/24 20:17:51 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack, char c, int opt)
{
	swapitems(stack, stack->top, 1);
	if (opt)
	{
		ft_printf("s%c\n", c);
		g_counter++;
	}
}

void	rotate(t_stack *stack, char c, int opt)
{
	int	i;

	i = stack->items;
	while (--i > 0)
		swapitems(stack, stack->top, i);
	if (opt)
	{
		ft_printf("r%c\n", c);
		g_counter++;
	}
}

void	revrotate(t_stack *stack, char c, int opt)
{
	int	i;

	i = 0;
	while (++i < stack->items)
		swapitems(stack, stack->top, i);
	if (opt)
	{
		ft_printf("rr%c\n", c);
		g_counter++;
	}
}

void	push(t_stack *a, t_stack *b, int dir)
{
	if (dir)
	{
		b->number[b->items] = a->number[a->top];
		b->items += 1;
		revrotate(b, 'b', 0);
		rotate(a, 'a', 0);
		a->number[a->items - 1] = 0;
		a->items -= 1;
		ft_printf("p%c\n", 'a');
		g_counter++;
	}
	else
	{
		a->number[a->items] = b->number[b->top];
		a->items += 1;
		revrotate(a, 'a', 0);
		rotate(b, 'b', 0);
		b->number[b->items - 1] = 0;
		b->items -= 1;
		ft_printf("p%c\n", 'b');
		g_counter++;
	}
}
