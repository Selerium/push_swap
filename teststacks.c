/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:25:21 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/28 15:25:29 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	test_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\nStack A: %d items | top: %d, end: %d\n",
		a->items, a->top, a->end);
	while (i < a->items)
	{
		j = a->numbers[i].position;
		ft_printf("%d\t", a->numbers[i].position);
		while (j--)
			ft_printf("-");
		ft_printf("\n");
		i++;
	}
	i = 0;
	ft_printf("\nStack B: %d items | top: %d, end: %d\n",
		b->items, b->top, b->end);
	while (i < b->items)
	{
		j = b->numbers[i].position;
		ft_printf("%d\t", b->numbers[i].position);
		while (j--)
			ft_printf("-");
		ft_printf("\n");
		i++;
	}
}
