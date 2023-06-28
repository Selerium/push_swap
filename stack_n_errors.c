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
	stack->numbers = (t_number *) ft_calloc(sizeof(t_number), argc - 1);
	if (!stack->numbers)
		ft_printexit(3);
	while (i < argc)
	{
		stack->numbers[i - 1].value = ft_atoi(argv[i]);
		i++;
	}
	stack->flag = 0;
	if (ft_strncmp(argv[0], "flag", 3) == 0)
		stack->flag = 1;
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
	stack->numbers = (t_number *) ft_calloc(sizeof(t_number), argc - 1);
	if (!stack->numbers)
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
