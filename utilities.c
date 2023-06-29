/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:26:33 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/29 14:12:03 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	ft_isspace(int s)
{
	if (s == 32 || (s >= 9 && s <= 13))
		return (1);
	else
		return (0);
}

void	swapitems(t_stack *stack, int top, int i)
{
	int	temp;

	temp = stack->numbers[top].value;
	stack->numbers[top].value = stack->numbers[i].value;
	stack->numbers[i].value = temp;
	temp = stack->numbers[top].position;
	stack->numbers[top].position = stack->numbers[i].position;
	stack->numbers[i].position = temp;
}

void	ft_freestacks(t_stack *a, t_stack *b)
{
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a)
		free(a);
	if (b)
		free(b);
}

int	complete(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->items && a->numbers[i].value > a->numbers[i - 1].value)
		i++;
	if (i == a->items)
		return (1);
	return (0);
}

char	**checkstring(char *av)
{
	char	**args;
	int		n;
	int		i;

	n = 0;
	i = -1;
	while (++i < (int) ft_strlen(av))
		if (!ft_isdigit(av[i]) && av[i] != '-' && !ft_isspace(av[i]))
			ft_printexit(2);
	while (ft_isspace(av[n]))
		n++;
	if (av[n] == '-')
		n++;
	while (ft_isdigit(av[n]))
		n++;
	while (ft_isspace(av[n]))
		n++;
	if (n == (int) ft_strlen(av))
		check_atol(av);
	av = ft_strjoin("flag ", av);
	args = ft_split(av, ' ');
	free (av);
	return (args);
}
