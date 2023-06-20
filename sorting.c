/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:56:25 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/20 19:11:12 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	set_position(t_stack *a)
{
	int	i;
	int	j;
	int	count;
	int	max;

	i = -1;
	max = 0;
	while (++i < a->items)
	{
		count = 0;
		j = -1;
		while (++j < a->items)
		{
			if (a->numbers[j].value > a->numbers[i].value)
				count++;
		}
		a->numbers[i].position = a->items - count;
	}
}

int	find_median(t_stack *a)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < a->items)
		sum += a->numbers[i++].position;
	return (sum / a->items);
}

void	sort_5(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	median;

	i = 0;
	median = find_median(a);
	while (a->items > 3 && i++ < a->chunk_size && n)
	{
		if (a->numbers[0].position < median)
			push(a, b, 1);
		else
			check_rotate(a, b, 'a');
	}
	if (a->items == 3)
		pushswap(a, b, 3);
	while (a->items < 5)
	{
		if (b->numbers[0].position < b->numbers[1].position)
			swap(b, 'b', 1);
		else if (b->numbers[0].position < b->numbers[b->items - 1].position)
			rotate(b, 'b', 1);
		push(a, b, 0);
	}
}

void	sort_100(t_stack *a, t_stack *b, int n)
{
	int	median;
	int	i;

	while (a->items > 5)
	{
		median = find_median(a);
		i = a->items;
		while (i--)
		{
			if (a->numbers[0].position < median)
				push(a, b, 1);
			else
				check_rotate(a, b, 'a');
		}
	}
}
