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

void	check_swap(t_stack *a, t_stack *b)
{
	if (b->number[0] < b->number[1])
		m_swap(a, b);
	else
		swap(a, 'a', 1);
}

void	sort3_1(t_stack *a, t_stack *b)
{
	if (a->number[0] < a->number[2])
		check_swap(a, b);
	else
	{
		if (a->number[2] > a->number[1])
			rotate(a, 'a', 1);
		else
		{
			check_swap(a, b);
			revrotate(a, 'a', 1);
		}
	}
}

void	sort3_2(t_stack *a, t_stack *b)
{
	if (a->number[0] > a->number[2])
		revrotate(a, 'a', 1);
	else
	{
		if (a->number[1] > a->number[2])
		{
			check_swap(a, b);
			rotate(a, 'a', 1);
		}
	}
}
