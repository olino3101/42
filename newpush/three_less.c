/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:50:56 by onault            #+#    #+#             */
/*   Updated: 2024/03/25 18:07:36 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_else(t_col *cola)
{
	printf("ra\n");
	ra_rb(cola);
	if (is_sorted(cola) == 0)
	{
		printf("sa\n");
		sa_sb(cola);
	}
	if (is_sorted(cola) == 0)
	{
		printf("rra");
		rra_rrb(cola);
	}
}

void	three(t_col *cola)
{
	if (is_sorted(cola) == 0)
	{
		if (cola->c[0] > cola->c[1] && cola->c[*cola->sizeofc - 1] > cola->c[0])
		{
			printf("sa\n");
			sa_sb(cola);
		}
		else if (cola->c[*cola->sizeofc - 1] < cola->c[0]
			&& cola->c[*cola->sizeofc - 1] < cola->c[1]
			&& cola->c[1] > cola->c[0])
		{
			rra_rrb(cola);
			printf("rra");
		}
		else
			three_else(cola);
	}
}
