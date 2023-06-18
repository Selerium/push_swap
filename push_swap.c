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
		a->chunk_size = 10;
}

void	pushswap(t_stack *a, t_stack *b, int n)
{
	if (!b)
		return ;
	if (n == 1)
		return ;
	if (n == 2)
	{
		if (a->number[0] > a->number[1])
		{
			if (b->number[0] < b->number[1])
				m_swap(a, b);
			else
				swap(a, 'a', 1);
		}
	}
	else if (n == 3)
	{
		if (a->number[0] > a->number[1])
			sort3_1(a, b);
		else
			sort3_2(a, b);
	}
	else
		sort(a, b, n);
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
		pushswap(a, b, argc - 1);
	ft_freestacks(a, b);
	return (0);
}
