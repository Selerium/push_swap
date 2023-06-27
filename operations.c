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
	if (stack->items > 1)
	{
		swapitems(stack, 0, 1);
		if (opt)
		{
			ft_printf("s%c\n", c);
			g_counter++;
		}
	}
}

void	rotate(t_stack *stack, char c, int opt)
{
	int	i;

	if (stack->items > 1)
	{
		i = stack->items;
		while (--i > 0)
			swapitems(stack, 0, i);
		if (opt)
		{
			ft_printf("r%c\n", c);
			g_counter++;
			updatetop(stack, 1);
			updateend(stack, 1);
		}
	}
}

void	revrotate(t_stack *stack, char c, int opt)
{
	int	i;

	if (stack->items > 1)
	{
		i = 0;
		while (++i < stack->items)
			swapitems(stack, 0, i);
		if (opt)
		{
			ft_printf("rr%c\n", c);
			g_counter++;
			updatetop(stack, 0);
			updateend(stack, 0);
		}
	}
}

//can probably remove the third last line in each~
void	push(t_stack *a, t_stack *b, int dir)
{
	g_counter++;
	if (dir)
	{
		if (a->items <= 0)
			return ;
		b->numbers[b->items].value = a->numbers[0].value;
		b->numbers[b->items].position = a->numbers[0].position;
		b->items += 1;
		revrotate(b, 'b', 0);
		rotate(a, 'a', 0);
		a->items -= 1;
		ft_printf("p%c\n", 'b');
	}
	else
	{
		if (b->items <= 0)
			return ;
		a->numbers[a->items].value = b->numbers[0].value;
		a->numbers[a->items].position = b->numbers[0].position;
		a->items += 1;
		revrotate(a, 'a', 0);
		rotate(b, 'b', 0);
		b->items -= 1;
		ft_printf("p%c\n", 'a');
	}
}
