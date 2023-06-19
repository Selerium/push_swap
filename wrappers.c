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

	temp = st->numbers[i].value;
	st->numbers[i].value = st->numbers[j].value;
	st->numbers[j].value = temp;
	temp = st->numbers[i].position;
	st->numbers[i].position = st->numbers[j].position;
	st->numbers[j].position = temp;
}

void	check_swap(t_stack *a, t_stack *b)
{
	if (b->numbers[0].position < b->numbers[1].position)
		m_swap(a, b);
	else
		swap(a, 'a', 1);
}

void	sort3_1(t_stack *a, t_stack *b)
{
	if (a->numbers[0].position < a->numbers[2].position)
		check_swap(a, b);
	else
	{
		if (a->numbers[2].position > a->numbers[1].position)
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
	if (a->numbers[0].position > a->numbers[2].position)
		revrotate(a, 'a', 1);
	else
	{
		if (a->numbers[1].position > a->numbers[2].position)
		{
			check_swap(a, b);
			rotate(a, 'a', 1);
		}
	}
}
