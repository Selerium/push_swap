/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:58:11 by jadithya          #+#    #+#             */
/*   Updated: 2022/12/19 18:08:34 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	m_swap(t_stack *a, t_stack *b)
{
	swap(a, 'a', 0);
	swap(b, 'b', 0);
	printf("ss\n");
}

void	m_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 'a', 0);
	rotate(b, 'b', 0);
	printf("rr\n");
}

void	m_revrotate(t_stack *a, t_stack *b)
{
	revrotate(a, 'a', 0);
	revrotate(b, 'a', 0);
	printf("rrr\n");
}
