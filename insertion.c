/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/21 22:22:46 by jadithya         ###   ########.fr       */
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

//void	insertionsortb(t_stack *a, t_stack *b, int n)
//{
//	int	i;
//	int	j;
//	int	k;

//	i = 0;
//	while (i++ < n - 1)
//	{
//		k = 0;
//		j = i;
//		rotate(b, 'b', 1);
//		while (j-- > 0)
//		{
//			if (b->number[0] > b->number[b->items - 1])
//			{
//				revrotate(b, 'b', 1);
//				swap(b, 'b', 1);
//				k++;
//			}
//		}
//		while (k < b->items / 2 && k-- > 0)
//			rotate(b, 'b', 1);
//		while (k-- > 1)
//			revrotate(b, 'b', 1);
//	}
//	rotate(b, 'b', 1);
//	while (b->items > 0)
//		push(a, b, 0);
//}

void	testsort(t_stack *a, t_stack *b, int n)
{
	int	j;
	int	small;

	while (n && a->items > 3)
	{
		j = 0;
		small = 0;
		while (++j < a->items)
		{
			if (a->number[j] < a->number[small])
				small = j;
		}
		ft_printf("\nSmall: %d\n", a->number[small]);
		while (small < a->items / 2 && small-- > 0)
			rotate(a, 'a', 1);
		while (small > a->items / 2 && small++ < a->items)
			revrotate(a, 'a', 1);
		push(a, b, 1);
	}
	pushswap(a, b, 3);
	while (b->items > 0)
		push(a, b, 0);
}
