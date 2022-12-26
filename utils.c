/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:22:46 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/27 14:22:46 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swapitems(t_stack *stack, int top, int i)
{
	int	temp;

	temp = stack->number[top];
	stack->number[top] = stack->number[i];
	stack->number[i] = temp;
}

void	ft_printexit(int n)
{
	if (n == 1)
		exit(1);
	if (n == 2)
	{
		ft_printf("Error\n");
		exit(2);
	}
	if (n == 3)
	{
		ft_printf("Error creating stack. Exiting.\n");
		exit(3);
	}
	exit(0);
}

int	middle(t_stack *a, int n)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < a->items)
	{
		j = -1;
		count = 0;
		while (++j < a->items)
		{
			if (a->number[j] < a->number[i])
				count++;
		}
		if (count == n / 2)
			break ;
	}
	return (a->number[i]);
}

int	max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (++i < a->items)
	{
		if (a->number[i] > a->number[max])
			max = i;
	}
	return (max);
}
