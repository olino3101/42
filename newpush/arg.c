/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:03:21 by onault            #+#    #+#             */
/*   Updated: 2024/03/23 13:06:16 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg_int(char *str)
{
	long	nb;

	nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

static int	check_dup(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strncmp(argv[j], argv[i]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (check_dup(argv) == 0)
		return (0);
	while (argv[i] != NULL)
	{
		if (check_arg_int(argv[i]) == 0)
			return (0);
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]) == 1)
				return (0);
			if ((ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != '-'))
			|| (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	insert_into_a(t_col *cola, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		cola->c[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}
