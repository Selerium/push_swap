/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/25 16:59:15 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	insertionsorta(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	j;
	int	k;

	if (b->items > 0)
		return ;
	i = 0;
	while (i++ < n - 1)
	{
		k = 0;
		j = i;
		rotate(a, 'a', 1);
		while (j-- > 0)
		{
			if (a->number[0] < a->number[a->items - 1])
			{
				revrotate(a, 'a', 1);
				swap(a, 'a', 1);
				k++;
			}
		}
		while (k < a->items / 2 && k-- > 0)
			rotate(a, 'a', 1);
		while (k-- > 1)
			revrotate(a, 'a', 1);
	}
	rotate(a, 'a', 1);
}

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
	while (n-- > 0)
		push(a, b, 1 - opt);
}
		//while (small < a->top)
		//	revrotate(a, 'a', 1);
		//while (small > a->top)
		//	rotate(a, 'a', 1);
	//while (n-- >= 0)
	//	push(a, b, 1);

void	boopbeep(t_stack *a, t_stack *b, int n, int opt)
{
	int	x;
	int	hold;

	x = middle(a, n);
	hold = 0;
	while (hold < (n / 2))
	{
		if (a->number[0] < x)
		{
			push(a, b, 1);
			hold++;
		}
		else
			rotate(a, 'a', 1);
	}
	ft_printf("test %d\n", n / 2);
	test_stacks(a, b);
	if (n > 4)
		boopbeep(a, b, n / 2, opt);
	testsort(a, b, (n / 2) - 3, opt);
	while (hold--)
		push(a, b, 0);
}

void	beepboop(t_stack *b, t_stack *a, int n, int opt)
{
	int	x;

	x = middle(b, n);
	while (b->items > n / 2)
	{
		if (a->number[0] > x)
			push(a, b, 1);
		else
			rotate(b, 'b', 1);
	}
	if (n > 3)
		beepboop(b, a, n / 2, opt);
	testsort(b, a, (n / 2) - 3, opt);
}
