/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:07:51 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/12 10:07:51 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	return (stack);
}

int	main(int argc, char **argv)
{
	s_stack	*a;
	s_stack	*b;

	checkparams(argc, argv);
	a = fillstack_a(argc, argv);
	b = fillstack_b(argc);
	ft_freestacks(a, b);
	return (0);
}