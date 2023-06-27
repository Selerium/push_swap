/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:26:33 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:36 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swapitems(t_stack *stack, int top, int i)
{
	int	temp;

	temp = stack->numbers[top].value;
	stack->numbers[top].value = stack->numbers[i].value;
	stack->numbers[i].value = temp;
	temp = stack->numbers[top].position;
	stack->numbers[top].position = stack->numbers[i].position;
	stack->numbers[i].position = temp;
}

void	ft_freestacks(t_stack *a, t_stack *b)
{
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a)
		free(a);
	if (b)
		free(b);
}

int	complete(t_stack *a, int argc)
{
	int	i;

	i = 0;
	while (a->numbers[i].value < a->numbers[i + 1].value && i < a->items)
		i++;
	if (i == a->items)
		return (1);
	return (0);
}

void	test_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\nStack A: %d items | top: %d, end: %d\n",
		a->items, a->top, a->end);
	while (i < a->items)
	{
		j = a->numbers[i].position;
		ft_printf("%d\t", a->numbers[i].position);
		while (j--)
			ft_printf("-");
		ft_printf("\n");
		i++;
	}
	i = 0;
	ft_printf("\nStack B: %d items | top: %d, end: %d\n",
		b->items, b->top, b->end);
	while (i < b->items)
	{
		j = b->numbers[i].position;
		ft_printf("%d\t", b->numbers[i].position);
		while (j--)
			ft_printf("-");
		ft_printf("\n");
		i++;
	}
}
