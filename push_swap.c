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

void	set_chunk_size(t_stack *a, int n)
{
	if (n <= 100)
		a->chunk_size = 20;
}

void	pushswap(t_stack *a, t_stack *b, int n)
{
	if (!b)
		return ;
	if (n == 1)
		return ;
	if (n == 2 && a->numbers[0].position > a->numbers[1].position)
		check_swap(a, b);
	else if (n == 3)
	{
		if (a->numbers[0].position > a->numbers[1].position)
			sort3_1(a, b);
		else
			sort3_2(a, b);
	}
	else if (n <= 5)
		sort_5(a, b, n);
	else if (n <= 100)
	{
		// sort_100(a, b, n);
		separate_chunks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	g_counter = 0;
	checkparams(argc, argv);
	if (argc == 2)
		ft_printexit(4);
	a = fillstack_a(argc, argv);
	b = fillstack_b(argc);
	set_chunk_size(a, argc - 1);
	if (complete(a, argc - 1) == 0)
	{
		set_position(a);
		pushswap(a, b, argc - 1);
	}
	test_stacks(a, b);
	ft_freestacks(a, b);
	return (0);
}
