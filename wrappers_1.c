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

void	sort4(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = n;
	while (n-- > 3)
		push(a, b, 1);
	pushswap(a, b, 3);
	if (b->number[1] && b->number[1] < b->number[0])
		swap(b, 'b', 1);
	while (n-- > 0)
	{	
		while (b->number[0] > a->number[0] && --i)
			rotate(a, 'a', 1);
		push(a, b, 0);
	}
	while (a->number[0] > a->number[a->items - 1])
		rotate(a, 'a', 1);
}

void	generalsort(t_stack *a, t_stack *b, int n)
{
	int	i;

	if (n)
	{
		push(a, b, 1);
		push(a, b, 1);
		if (b->number[0] > b->number[1])
			swap(b, 'b', 1);
	}
	while (a->items > 0)
	{
		push(a, b, 1);
		i = 0;
		while (b->number[0] > b->number[1] && ++i != b->items)
		{
			swap(b, 'b', 1);
			rotate(b, 'b', 1);
		}
		while (b->number[0] > b->number[b->items - 1])
			rotate(b, 'b', 1);
	}
}

void	insertionsort(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	j;

	if (b->items != 0)
		return ;
	i = 0;
	while (i++ < n)
	{
		j = 0;
		while (++j < i)
			rotate(a, 'a', 1);
		while (j-- > 0)
		{
			if (a->number[1] < a->number[0])
			{
				swap(a, 'a', 1);
				revrotate(a, 'a', 1);
			}
		}
	}
}
