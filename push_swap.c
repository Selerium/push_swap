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

void	ft_printexit(int n)
{
	if (n == 1)
		exit(1);
	if (n == 2)
	{
		ft_printf("Error\n");
		exit(2);
	}
	if (n == 3)
	{
		ft_printf("Error creating stack. Exiting.\n");
		exit(3);
	}
}

int	checknum(char *num)
{
	int	result;

	if ((num[0] != '-' && ft_strlen(num) > 10) || ft_strlen(num) > 11)
		return (-1);
	if (num[0] == '0' || (num[0] == '-' && num[1] == '1'))
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
	while (num[i])
	{
		if (ft_isalpha(num[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	checkparams(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		ft_printexit(1);
	while (i < argc)
	{
		if (checknum(argv[i]) != 0)
			ft_printexit(2);
		i++;
	}
}

void	*ft_malloc(int size)
{
	s_item	*stack;

	stack = (s_item *) malloc (size * sizeof(s_item));
	if (!stack)
		return (NULL);
	return (stack);
}

s_item	*fillstack(int argc, char **argv)
{
	int		i;
	s_item	*stack;

	i = 1;
	stack = ft_malloc((argc - 1) * sizeof(*stack));
	if (!stack)
		ft_printexit(3);
	while (i < argc)
	{
		stack[i].number = ft_atoi(argv[i]);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	s_item	*stack;

	checkparams(argc, argv);
	stack = fillstack(argc, argv);
	ft_printf("%d, %d, %d", stack[0].number, stack[1].number, stack[2].number);
	free (stack);
	return (0);
}