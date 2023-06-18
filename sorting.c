/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:56:25 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/18 20:39:35 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_median(t_stack *a)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < a->chunk_size && i < a->items)
		sum += a->number[i++];
	if (a->items > a->chunk_size)
		return (sum / a->chunk_size);
	return (sum / a->items);
}

void	check_rotate(t_stack *a, t_stack *b, char c)
{
	if (b->number[0] < b->number[b->items - 1])
		m_rotate(a, b);
	else
		rotate(a, c, 1);
}

void	sort_5(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	median;

	i = 0;
	median = find_median(a);
	while (a->items > 3 && i++ < a->chunk_size && n)
	{
		if (a->number[0] < median)
			push(a, b, 1);
		else
			check_rotate(a, b, 'a');
	}
	if (a->items == 3)
		pushswap(a, b, 3);
	while (b->items)
	{
		if (b->number[0] < b->number[1])
			swap(b, 'b', 1);
		else if (b->number[0] < b->number[b->items - 1])
			rotate(b, 'b', 1);
		push(a, b, 0);
	}
}

void	sort(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	median;

	i = 0;
	median = find_median(a);
	while (a->items > 3 && i++ < a->chunk_size && n)
	{
		if (a->number[0] < median)
			push(a, b, 1);
		else
			check_rotate(a, b, 'a');
	}
	if (a->items == 3)
		pushswap(a, b, 3);
	while (b->items)
	{
		if (b->number[0] < b->number[1])
			swap(b, 'b', 1);
		else if (b->number[0] < b->number[b->items - 1])
			rotate(b, 'b', 1);
		push(a, b, 0);
	}
}
