/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:38:06 by onault            #+#    #+#             */
/*   Updated: 2024/03/25 15:40:47 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;
	size_t				i;

	cdst = dst;
	csrc = src;
	if (!dst || !src)
		return (NULL);
	if (dst >= src && dst < src + len)
	{
		i = len;
		while (i-- > 0)
			cdst[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}

void	pa_pb(t_col *cola, t_col *colb)
{
	int	temp;

	if (*(colb->sizeofc) == 0)
		return ;
	(*(cola->sizeofc)) += 1;
	(*(colb->sizeofc)) -= 1;
	temp = cola->c[0];
	cola->c[0] = colb->c[0];
	ft_memmove(&cola->c[2], &cola->c[1], sizeof(int) * (*(cola->sizeofc) - 1));
	cola->c[1] = temp;
	if (*colb->sizeofc >= 1)
		ft_memmove(&colb->c[0], &colb->c[1], sizeof(int) * (*(colb->sizeofc)));
}

void	ra_rb(t_col *col)
{
	int	temp;

	if (*(col->sizeofc) == 0)
		return ;
	temp = col->c[0];
	ft_memmove(&col->c[0], &col->c[1], sizeof(int) * (*(col->sizeofc) - 1));
	col->c[(*(col->sizeofc)) - 1] = temp;
}

void	rra_rrb(t_col *col)
{
	int	temp;

	if (*(col->sizeofc) == 0)
		return ;
	temp = col->c[*col->sizeofc - 1];
	ft_memmove(&col->c[1], &col->c[0], sizeof(int) * (*(col->sizeofc) - 1));
	col->c[0] = temp;
}

void	sa_sb(t_col *col)
{
	int	temp;

	temp = col->c[1];
	col->c[1] = col->c[0];
	col->c[0] = temp;
}
