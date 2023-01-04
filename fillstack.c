/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:15:00 by jadithya          #+#    #+#             */
/*   Updated: 2023/01/04 18:11:39 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*fillstack_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		ft_printexit(3);
	stack->number = (int *) ft_calloc(sizeof(int), argc - 1);
	if (!stack->number)
		ft_printexit(3);
	while (i < argc)
	{
		stack->number[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack->items = argc - 1;
	stack->top = 0;
	stack->end = stack->items - 1;
	return (stack);
}

t_stack	*fillstack_b(int argc)
{
	t_stack	*stack;

	stack = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		ft_printexit(3);
	stack->number = (int *) ft_calloc(sizeof(int), argc - 1);
	if (!stack->number)
		ft_printexit(3);
	stack->items = 0;
	stack->top = 0;
	stack->end = 0;
	return (stack);
}

void	cleanup(t_stack *a, t_stack *b, int hold)
{
	int	x;
	int	i;

	x = middle(b, hold);
	i = 0;
	while (i++ < hold)
	{
		if (b->number[0] > x)
			push(a, b, 0);
		else
			rotate(b, 'b', 1);
	}
	while (i-- > hold / 2)
		push(a, b, 1);
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

void	checkfill(int n, char **array)
{
	
}