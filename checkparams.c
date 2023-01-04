/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparams.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:55:15 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/24 15:55:15 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	checknum(char *num)
{
	int	result;

	if ((num[0] != '-' && ft_strlen(num) > 10) || ft_strlen(num) > 11)
		return (-1);
	if ((num[0] == '0' && num[1] == '\0') || (num[0] == '-' && num[1] == '1'))
		return (0);
	result = ft_atoi(num);
	if (result == 0 || result == -1)
		return (-1);
	return (0);
}

int	checkword(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

void	checkparams(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		ft_printexit(2);
	if (argc < 3)
		checkstring(argv[1]);
	else
	{
		while (i < argc)
		{
			if (checknum(argv[i]) != 0 || checkword(argv[i]) != 0)
				ft_printexit(2);
			j = i + 1;
			while (j < argc)
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					ft_printexit(2);
				j++;
			}
			i++;
		}
	}
}

int	checksort(t_stack *a)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < a->items && flag == 0)
	{
		j = i;
		while (++j < a->items && flag == 0)
		{
			if (a->number[i] > a->number[j])
				flag = 1;
		}
	}
	return (flag);
}

void	checkstring(char *array)
{
	char	**split;
	int		n;

	split = ft_split(array, ' ');
	n = 0;
	while (split[n])
		n++;
	if (n < 2)
		ft_printexit(2);
	else
		checkparams(n, split);
	n = 0;
	while (split[n])
	{
		free(split[n]);
		n++;
	}
}
