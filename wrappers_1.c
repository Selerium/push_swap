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

void	sort3_1(s_stack *a)
{
	if (a->number[0] < a->number[2])
				swap(a, 'a');
	else
	{
		if (a->number[2] > a->number[1])
			rotate(a, 'a');
		else
		{
			swap(a, 'a');
			revrotate(a, 'a');
		}
	}
}

void	sort3_2(s_stack *a)
{
	if (a->number[0] > a->number[2])
		revrotate(a, 'a');
	else
	{
		if (a->number[1] > a->number[2])
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
	}
}

void	sendtoB(s_stack *a, s_stack *b, int n)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < a->items)
	{
		if (a->number[temp] < a->number[i])
			temp = i;
		i++;
	}
	if (b->top && n)
		return ;
	// push(a, b, 1);
}