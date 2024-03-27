/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:31:10 by onault            #+#    #+#             */
/*   Updated: 2024/03/23 11:36:04 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_col(t_col *cola, t_col *colb, int argc)
{
	cola->c = malloc((argc) * sizeof(int));
	colb->c = malloc((argc) * sizeof(int));
	cola->sizeofc = malloc(sizeof(int));
	colb->sizeofc = malloc(sizeof(int));
	*cola->sizeofc = argc - 1;
	*colb->sizeofc = 0;
	if (!cola->c || !colb->c || !colb->sizeofc || !cola->sizeofc)
	{
		free_col(cola, colb);
		return (0);
	}
	return (1);
}

static	void	cpy_newarr(t_col *cola, int *newarr)
{
	int	i;

	i = 0;
	while (i != *cola->sizeofc)
	{
		cola->c[i] = newarr[i];
		i++;
	}
}

void	remove_gap(t_col *cola)
{
	int	i;
	int	j;
	int	smaller;
	int	*newarr;

	i = 0;
	smaller = 0;
	newarr = malloc(sizeof(int) * (*cola->sizeofc));
	if (!newarr)
		return ;
	while (i != *cola->sizeofc)
	{
		j = 0;
		while (j != *cola->sizeofc)
		{
			if (cola->c[i] > cola->c[j])
				smaller++;
			j++;
		}
		newarr[i] = smaller;
		smaller = 0;
		i++;
	}
	cpy_newarr(cola, newarr);
	free(newarr);
}
