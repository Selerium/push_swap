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
