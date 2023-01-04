/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by jadithya          #+#    #+#             */
/*   Updated: 2023/01/03 13:57:41 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	testsort(t_stack *a, t_stack *b, int n, int opt)
{
	int	j;
	int	small;

	while (a->items > 3)
	{
		a->top = 0;
		j = 0;
		small = 0;
		while (++j < a->items)
		{
			if (a->number[j] < a->number[small])
				small = j;
		}
		while (small < a->items / 2 && small-- > 0)
			rotate(a, 'a', 1);
		while (small >= a->items / 2 && small++ < a->items)
			revrotate(a, 'a', 1);
		push(a, b, opt);
	}
	pushswap(a, b, 3);
	while (n-- > 3)
		push(a, b, 1 - opt);
}

void	boopbeep(t_stack *a, t_stack *b, int n)
{
	int	x;
	int	y;
	int	hold;

	x = middle(a, n);
	y = 125;
	hold = 0;
	while (hold < (n / 2))
	{
		if (a->number[0] < x)
		{
			push(a, b, 1);
			hold++;
		}
		else if (b->items > 2 && 0 && b->number[0] < y)
			m_rotate(a, b);
		else
			rotate(a, 'a', 1);
	}
	//cleanup(a, b, hold);
	if (hold > 3)
		boopbeep(a, b, n - hold);
	else
		testsort(a, b, n - hold, 1);
	beepboop(b, a, hold);
}

void	beepboop(t_stack *b, t_stack *a, int n)
{
	int	i;
	int	x;

	i = 0;
	while (i++ < n)
	{
		x = max(b);
		while (x < b->items / 2 && x-- > 0)
			rotate(b, 'b', 1);
		while (x >= b->items / 2 && x++ < b->items)
			revrotate(b, 'b', 1);
		push(a, b, 0);
	}
}
