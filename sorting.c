/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:56:25 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/27 23:01:57 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

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
		// else if (b->numbers[0].position < b->numbers[b->items - 1].position)
		// 	rotate(b, 'b', 1);
		push(a, b, 0);
	}
}

void	finddirection(t_stack *a, int min, int max)
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
			rotate(a, 'a', 1);
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
			finddirection(a, min, max);
			push(a, b, 1);
		}
		i++;
	}
}

// int	check_above_median(t_stack *a, int median)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < a->items)
// 		if (a->numbers[i].position < median)
// 			return (1);
// 	return (0);
// }



// void	rotate_to_zero(t_stack *a)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < a->items)
// 		if (a->numbers[i].position == 1)
// 			break ;
// 	if (i > a->items / 2)
// 		while (i--)
// 			revrotate(a, 'a', 1);
// 	else
// 		while (i--)
// 			rotate(a, 'a', 1);
// }

// int	find_run(t_stack *a, t_stack *b, int opt)
// {
// 	int	i;
// 	int	result;

// 	i = 1;
// 	if (a->numbers[0].position == a->numbers[1].position - 1)
// 	{
// 		i++;
// 		while (a->numbers[i].position == a->numbers[i + 1].position - 1)
// 			i++;
// 	}
// 	result = i;
// 	while (opt % 2 == 0 && i--)
// 		push(a, b, 1);
// 	while (opt % 2 != 0 && i--)
// 		rotate(a, 'a', 1);
// 	if (opt % 2 == 0)
// 		opt++;
// 	else
// 		opt--;
// 	return (result + 1);
// }

// void	merge_to_b(t_stack *a, t_stack *b)
// {
// 	if (a->numbers[0].position < b->numbers[0].position)
// 		push(a, b, 1);
// 	rotate(b, 'b', 1);
// 	while (b->numbers[b->end].position <= b->numbers[0].position)
// 	{
// 		if (a->numbers[0].position < b->numbers[0].position)
// 			push(a, b, 1);
// 		rotate(b, 'b', 1);
// 	}
// 	while (b->numbers[b->end].position <= a->numbers[0].position)
// 	{
// 		push(a, b, 1);
// 		rotate(b, 'b', 1);
// 	}
// }

// void	merge_to_a(t_stack *a, t_stack *b)
// {
// 	if (b->numbers[0].position < a->numbers[0].position)
// 		push(a, b, 0);
// 	rotate(a, 'a', 1);
// 	while (a->numbers[a->end].position <= a->numbers[0].position)
// 	{
// 		if (b->numbers[0].position < a->numbers[0].position)
// 			push(a, b, 0);
// 		rotate(a, 'a', 1);
// 	}
// 	while (a->numbers[a->end].position <= b->numbers[0].position)
// 	{
// 		push(a, b, 0);
// 		rotate(a, 'a', 1);
// 	}
// }

// void	sort_100(t_stack *a, t_stack *b, int n)
// {
// 	int	i;

// 	i = 0;
// 	rotate_to_zero(a);
// 	while (i < n)
// 		i += find_run(a, b, n);
// 	while (b->items)
// 	{
// 		merge_to_a(a, b);
// 		merge_to_b(a, b);
// 	}
// }

	//while (b->items)
	//{
	//}
//void	sort_b(t_stack *b, int n)
//{
//	int	i;

//	i = 0;
//	while (i++ < n)
//	{
		
//	}
//}

	//int	median;
	//int	i;

	//median = find_median(a);
	//i = a->items;
	//while (check_above_median(a, median))
	//{
	//	if (a->numbers[0].position <= median)
	//		push(a, b, 1);
	//	else
	//		check_rotate(a, b, 'a');
	//}
	//sort_b(b, i);