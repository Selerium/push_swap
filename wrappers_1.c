/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:11:23 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/27 17:11:23 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *st, int i, int j)
{
	int	temp;

	temp = st->number[i];
	st->number[i] = st->number[j];
	st->number[j] = temp;
}

void	sort3_1(t_stack *a)
{
	if (a->number[0] < a->number[2])
		swap(a, 'a', 1);
	else
	{
		if (a->number[2] > a->number[1])
			rotate(a, 'a', 1);
		else
		{
			swap(a, 'a', 1);
			revrotate(a, 'a', 1);
		}
	}
}

void	sort3_2(t_stack *a)
{
	if (a->number[0] > a->number[2])
		revrotate(a, 'a', 1);
	else
	{
		if (a->number[1] > a->number[2])
		{
			swap(a, 'a', 1);
			rotate(a, 'a', 1);
		}
	}
}

void	generalsort(t_stack *a, t_stack *b, int n)
{
	int	median;

	if (!b->items || n)
		median = 0;
	median = ft_median(a);
	ft_printf("mid: %d\n", median);
	ft_quicksort1(a, b, median);
	test_stacks(a, b);
	ft_quicksort2(b, a, median);
}

void	ft_quicksort1(t_stack *a, t_stack *b, int median)
{
	if (a->items || b->items || median || 1)
		ft_printf("test\n");
	while (a->items > 0)
	{
		push(a, b, 1);
		if (b->number[0] < median && b->items > 1)
			rotate(b, 'b', 1);
	}
}

void	ft_quicksort2(t_stack *b, t_stack *a, int median)
{
	if (a->items || b->items || median || 1)
		ft_printf("test\n");
	while (b->items > 0)
	{
		push(a, b, 0);
		if (a->number[0] >= median && a->items > 1)
			rotate(a, 'a', 1);
	}
}
