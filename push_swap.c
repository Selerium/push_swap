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

void	pushswap(t_stack *a, t_stack *b, int n)
{
	if (n == 2)
	{
		if (a->number[0] > a->number[1])
			swap(a, 'a', 1);
	}
	else if (n == 3)
	{
		if (a->number[0] > a->number[1])
			sort3_1(a);
		else
			sort3_2(a);
	}
	// else if (n <= 5)
	// {
	// 	sendtoB(a, b, n);		//dir: 1 = a->b, 0 = b->a
	// 	pushswap(a, b, n - 1);
	// 	push(a, b, 0);
	// }
}

void	test_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("Stack A: %d items\n", a->items);
	while (i < a->items)
	{
		ft_printf("%d\n", a->number[i]);
		i++;
	}
	i = 0;
	ft_printf("Stack B: %d items\n", b->items);
	while (i < b->items)
	{
		ft_printf("%d\n", b->number[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	checkparams(argc, argv);
	if (argc == 2)
		ft_printexit(4);
	a = fillstack_a(argc, argv);
	b = fillstack_b(argc);
	pushswap(a, b, argc - 1);
	test_stacks(a, b);
	ft_freestacks(a, b);
	return (0);
}