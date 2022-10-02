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

void	swap(s_stack *stack, char c)
{
	swapitems(stack, stack->top, 1);
	ft_printf("s%c\n", c);
}

void	rotate(s_stack *stack, char c)
{
	int	i;

	i = stack->items;
	while (--i > 0)
		swapitems(stack, stack->top, i);
	ft_printf("r%c\n", c);
}

void	revrotate(s_stack *stack, char c)
{
	int	i;

	i = 0;
	while (++i < stack->items)
		swapitems(stack, stack->top, i);
	ft_printf("rr%c\n", c);
}

// void	push(s_stack *a, s_stack *b, int dir)
// {
// 	int	i;

// 	i = 0;
// 	while (i < )
// }