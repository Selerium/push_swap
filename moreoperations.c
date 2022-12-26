/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:58:11 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/26 22:05:42 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	m_swap(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swap(a, 'a', 0);
	swap(b, 'b', 0);
}

void	m_rotate(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate(a, 'a', 0);
	rotate(b, 'b', 0);
}

void	m_revrotate(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	revrotate(a, 'a', 0);
	revrotate(b, 'a', 0);
}
