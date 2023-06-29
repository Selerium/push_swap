/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longchecks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:06:24 by jadithya          #+#    #+#             */
/*   Updated: 2023/06/28 22:06:24 by jadithya         ###   ########.fr       */
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

void	check_atol(char *s)
{
	int		index;
	long	number;
	int		j;

	j = -1;
	index = 0;
	number = 0;
	while (ft_isspace((int) s[index]))
		index++;
	if (s[index] == '-' || s[index] == '+')
		j = index++;
	while (ft_isdigit(s[index]))
	{
		number *= 10;
		number += (((int) s[index]) - 48);
		index++;
	}
	if (j > -1 && s[j] == '-')
		number *= -1;
	if (number > INT_MAX || number < INT_MIN || (s[j] == '-'
			&& (!s[j + 1] || s[j + 1] == ' ')))
		ft_printexit(2);
	ft_printexit(4);
}

void	check_long(char **s, int i)
{
	int		index;
	long	number;
	int		j;

	j = -1;
	index = 0;
	number = 0;
	while (ft_isspace((int) s[i][index]))
		index++;
	if (s[i][index] == '-' || s[i][index] == '+')
		j = index++;
	while (ft_isdigit(s[i][index]))
	{
		number *= 10;
		number += (((int) s[i][index]) - 48);
		index++;
	}
	if (j > -1 && s[i][j] == '-')
		number *= -1;
	if (number > INT_MAX || number < INT_MIN)
		ft_otherexit(s);
}
