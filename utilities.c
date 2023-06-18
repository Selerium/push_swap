/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:26:33 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/17 21:27:11 by jadithya         ###   ########.fr       */
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

void	ft_freestacks(t_stack *a, t_stack *b)
{
	if (a->number)
		free(a->number);
	if (b->number)
		free(b->number);
	if (a)
		free(a);
	if (b)
		free(b);
}

int	complete(t_stack *a, int argc)
{
	int	i;

	i = 0;
	while (a->number[i] < a->number[i + 1] && i < argc - 1)
		i++;
	if (i == argc - 1)
		return (1);
	return (0);
}

void	test_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("\nStack A: %d items | top: %d, end: %d\n",
		a->items, a->top, a->end);
	while (i < a->items)
	{
		ft_printf("%d\n", a->number[i]);
		i++;
	}
	i = 0;
	ft_printf("\nStack B: %d items | top: %d, end: %d\n",
		b->items, b->top, b->end);
	while (i < b->items)
	{
		ft_printf("%d\n", b->number[i]);
		i++;
	}
}
