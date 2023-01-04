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
	if (n == 1)
		return ;
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
	//else if (n < 5)
	//	sort4(a, b, n);
	else
		boopbeep(a, b, n);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;
	int		n;

	n = 0;
	checkparams(argc, argv);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[n])
			n++;
		if (n < 2)
			ft_free(split);
	}
	if (n != 0)
		checkfill(n, split);
	else
		checkfill(argc, argv);
	if (checksort(a) == 1)
		pushswap(a, b, argc - 1);
	ft_freestacks(a, b);
	return (0);
}
