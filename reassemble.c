/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassemble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:25:50 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/27 20:25:50 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_rotate(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		if (b->items > 1
			&& b->numbers[b->top].position < b->numbers[b->end].position)
			m_rotate(a, b);
		else
			rotate(a, c, 1);
	}
}
	//else
	//{
	//	if (b->numbers[0].position == b->smallest)
	//	{
	//		push(a, b, 0);
	//		b->smallest++;
	//		if (b->numbers[0].position != b->items)
	//			m_rotate(a, b);
	//		else
	//			rotate(a, c, 1);
	//	}
	//	else
	//		rotate(b, 'b', 1);
	//}

void	check_revrotate(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
	{
		if (b->items > 1
			&& b->numbers[b->top].position > b->numbers[b->end].position)
			m_revrotate(a, b);
		else
			revrotate(a, c, 1);
	}
}

int	findpos(t_stack *b, int n)
{
	int	i;

	i = -1;
	while (++i < b->items)
		if (b->numbers[i].position == n)
			return (i);
	return (0);
}

void	backtoa(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->items > 1)
	{
		pos = findpos(b, b->items);
		if (pos > b->items / 2)
			while (pos++ < b->items)
				revrotate(b, 'b', 1);
		else
			while (pos--)
				rotate(b, 'b', 1);
		push(a, b, 0);
	}
	push(a, b, 0);
}
