/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:59:42 by jadithya          #+#    #+#             */
/*   Updated: 2022/06/22 15:07:23 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s1;

	s1 = (char *) s;
	i = 0;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
	return (s);
}