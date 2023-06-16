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

int	ft_median(t_stack *a)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = a->number[0];
	min = a->number[0];
	while (i < a->items)
	{
		if (a->number[i] > max)
			max = a->number[i];
		if (a->number[i] < min)
			min = a->number[i];
		i++;
	}
	return ((max - min) / 2);
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
	//while (i < a->items / 2 && i-- > 0)
	//	rotate(a, 'a', 1);
	//while (i >= a->items / 2 && i++ < a->items)
	//	revrotate(a, 'a', 1);
}