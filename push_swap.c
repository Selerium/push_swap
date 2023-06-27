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
		separate_chunks(a, b);
	}
}

static int	ft_isspace(int s)
{
	if (s == 32 || (s >= 9 && s <= 13))
		return (1);
	else
		return (0);
}

char	**checkstring(char *av, t_stack *a, t_stack *b)
{
	char	**args;
	int		n;

	n = 0;
	while (ft_isspace(av[n]))
		n++;
	if (av[n] == '-')
		n++;
	while (ft_isdigit(av[n]))
		n++;
	while (ft_isspace(av[n]))
		n++;
	if (n == ft_strlen(av))
		ft_printexit(4);
	av = ft_strjoin("./push_swap ", av);
	args = ft_split(av, ' ');
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	g_counter = 0;
	if (argc == 2)
	{
		argv = checkstring(argv[1], a, b);
		argc = 0;
		while (argv[argc])
			argc++;
	}
	checkparams(argc, argv);
	a = fillstack_a(argc, argv);
	b = fillstack_b(argc);
	set_chunk_size(a, a->items);
	if (complete(a, a->items) == 0)
	{
		set_position(a);
		pushswap(a, b, a->items);
	}
	test_stacks(a, b);
	ft_freestacks(a, b);
	return (0);
}
