/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:58:11 by jadithya          #+#    #+#             */
/*   Updated: 2022/10/02 17:18:41 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	m_swap(t_stack *a, t_stack *b)
{
	swap(a, 'a');
	swap(b, 'b');
}

void	m_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	m_revrotate(t_stack *a, t_stack *b)
{
	revrotate(a, 'a');
	revrotate(b, 'a');
}
