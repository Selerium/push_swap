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

void	swapitems(s_stack *stack, int top, int i)
{
	int	temp;

	temp = stack->number[top];
	stack->number[top] = stack->number[i];
	stack->number[i] = temp;
}

s_stack	*fillstack_a(int argc, char **argv)
{
	int		i;
	s_stack	*stack;

	i = 1;
	stack = (s_stack *) ft_calloc(sizeof(s_stack), 1);
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
	return (stack);
}

s_stack	*fillstack_b(int argc)
{
	s_stack	*stack;

	stack = (s_stack *) ft_calloc(sizeof(s_stack), 1);
	if (!stack)
		ft_printexit(3);
	stack->number = (int *) ft_calloc(sizeof(int), argc - 1);
	if (!stack->number)
		ft_printexit(3);
	stack->items = 0;
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
