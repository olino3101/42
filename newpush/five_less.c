/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:58:37 by onault            #+#    #+#             */
/*   Updated: 2024/03/25 18:25:15 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_semi_sorted(t_col *cola)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i != *cola->sizeofc - 1)
	{
		if (cola->c[i] > cola->c[i + 1] && flag == 0)
			flag = 1;
		else if (cola->c[i] > cola->c[i + 1] && flag == 1)
			return (0);
		i++;
	}
	if (flag == 0)
		return (1);
	else if (cola->c[*cola->sizeofc - 1] < cola->c[0])
		return (1);
	else
		return (0);
}

static void	put_backa(t_col *cola, t_col *colb)
{
	while (*colb->sizeofc != 0)
	{
		if (cola->c[0] - 1 == colb->c[0])
		{
			printf("pa\n");
			pa_pb(cola, colb);
		}
		else
		{
			printf("ra\n");
			ra_rb(cola);
		}
	}
	while (is_sorted(cola) == 0)
	{
		printf("rra\n");
		rra_rrb(cola);
	}
}

void	five_less(t_col *cola, t_col *colb)
{
	while (is_semi_sorted(cola) == 0)
	{
		if (cola->c[0] < cola->c[1] && cola->c[0] < cola->c[*cola->sizeofc - 1]
			&& *colb->sizeofc != 2)
		{
			printf("pb\n");
			pa_pb(colb, cola);
			if (*colb->sizeofc == 2 && colb->c[0] < colb->c[1])
			{
				printf("sb\n");
				sa_sb(colb);
			}
		}
		else if (cola->c[*cola->sizeofc - 1] < cola->c[0])
		{
			printf("rra\n");
			rra_rrb(cola);
		}
		else
		{
			printf("sa\n");
			sa_sb(cola);
		}
	}
	put_backa(cola, colb);
}
