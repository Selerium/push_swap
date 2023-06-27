/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:56:25 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/27 23:29:38 by jadithya         ###   ########.fr       */
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
	while (a->items < n)
	{
		if (b->numbers[0].position < b->numbers[1].position)
			swap(b, 'b', 1);
		push(a, b, 0);
	}
}

void	finddirection(t_stack *a, t_stack *b, int min, int max)
{
	int	i;
	int	near;
	int	end;

	i = 0;
	end = -1;
	near = -1;
	while (i < a->items)
	{
		if (near < 0
			&& a->numbers[i].position <= max && a->numbers[i].position >= min)
			near = i;
		if (end < 0
			&& a->numbers[a->items - 1 - i].position <= max
			&& a->numbers[a->items - 1 - i].position >= min)
			end = i + 1;
		i++;
	}
	if (end > near)
		while (near--)
			check_rotate(a, b, 'a');
	else
		while (end--)
			revrotate(a, 'a', 1);
}

void	separate_chunks(t_stack *a, t_stack *b)
{
	int	chunks;
	int	min;
	int	max;
	int	i;

	chunks = a->items / a->chunk_size;
	i = 0;
	while (a->items)
	{
		min = a->chunk_size * i + 1;
		if (i < chunks)
			max = min + a->chunk_size - 1;
		else
			max = a->items + b->items;
		while (b->items < max)
		{
			finddirection(a, b, min, max);
			push(a, b, 1);
		}
		i++;
	}
}
