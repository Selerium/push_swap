/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassemble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:25:50 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/27 20:25:50 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	findpos(t_stack *b, int n)
{
	int	i;

	i = -1;
	while (++i < b->items)
		if (b->numbers[i].position == n)
			return (i);
}

void	backtob(t_stack *a, t_stack *b)
{
	int	pos;
	int	max;

	max = a->items;
	while (a->items > 5)
	{
		// pos = findpos(a, max--);
		// if (pos > a->items / 2)
		// 	while (pos++ < a->items)
		// 		revrotate(a, 'a', 1);
		// else
		// 	while (pos--)
		// 		rotate(a, 'a', 1);
		push(a, b, 1);
	}
	pushswap(a, b, 5);
}

void	backtoa(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->items > 1)
	{
		pos = findpos(b, b->items);
		if (pos > b->items / 2)
			while (pos++ < b->items)
				revrotate(b, 'b', 1);
		else
			while (pos--)
				rotate(b, 'b', 1);
		push(a, b, 0);
	}
	push(a, b, 0);
}
