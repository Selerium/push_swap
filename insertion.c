/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/26 20:34:01 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//void	insertionsorta(t_stack *a, t_stack *b, int n)
//{
//	int	i;
//	int	j;
//	int	k;

//	if (b->items > 0)
//		return ;
//	i = 0;
//	while (i++ < n - 1)
//	{
//		k = 0;
//		j = i;
//		rotate(a, 'a', 1);
//		while (j-- > 0)
//		{
//			if (a->number[0] < a->number[a->items - 1])
//			{
//				revrotate(a, 'a', 1);
//				swap(a, 'a', 1);
//				k++;
//			}
//		}
//		while (k < a->items / 2 && k-- > 0)
//			rotate(a, 'a', 1);
//		while (k-- > 1)
//			revrotate(a, 'a', 1);
//	}
//	rotate(a, 'a', 1);
//}

	//ft_printf("\ntest %d %d %d\n", n, a->items, a->items + b->items);
	//ft_printf("\n------\n");
	//test_stacks(a, b);
	//ft_printf("\n------\n");
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
	if (hold > 3)
	{
		boopbeep(a, b, n - hold, opt);
	}
	else
		testsort(a, b, n - hold, opt);
	//test_stacks(a, b);
	beepboop(b, a, hold, opt);
}

void	beepboop(t_stack *b, t_stack *a, int n, int opt)
{
	int	i;
	int	x;

	i = 0;
	if (a->items == 2039 && opt)
		return ;
	while (i++ < n)
	{
		x = max(b);
		//ft_printf("%d %d\n", b->number[x], x);
		while (x < b->items / 2 && x-- > 0) 
			rotate(b, 'b', 1);
		while (x >= b->items / 2 && x++ < b->items)
			revrotate(b, 'b', 1);
		//ft_printf("%d\n", b->number[0]);
		push(a, b, 0);
	}
}

	//if (hold <= 10)
	//	testsort(a, b, (n - hold), opt);
	//else
	//{
	//	boopbeep(a, b, n - hold, opt);
	//	testsort(a, b, (n - hold), opt);
	//	x = hold;
	//	while (hold--)
	//		push(a, b, 0);
	//	testsort(a, b, x, opt);
	//}