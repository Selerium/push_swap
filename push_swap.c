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
		a->chunk_size = 17;
	else if (n <= 500)
		a->chunk_size = 42;
	else
		a->chunk_size = 60;
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
	else
		separate_chunks(a, b);
}

void	freeav(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argv = checkstring(argv[1]);
		argc = 0;
		while (argv[argc])
			argc++;
	}
	checkparams(argc, argv);
	a = fillstack_a(argc, argv);
	b = fillstack_b(argc);
	set_chunk_size(a, a->items);
	set_position(a);
	if (complete(a) == 0)
		pushswap(a, b, a->items);
	if (a->flag)
		freeav(argv);
	ft_freestacks(a, b);
	return (0);
}
