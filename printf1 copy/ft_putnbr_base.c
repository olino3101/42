/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:36 by onault            #+#    #+#             */
/*   Updated: 2024/02/18 17:23:44 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_base(size_t nbr, int i, char *base, int count)
{
	int	remainder;

	if (nbr >= i)
		count = (print_base(nbr / i, i, &base[0], count));
	remainder = nbr % i;
	write(1, &base[remainder], 1);
	return (count + 1);
}

int	ft_putnbr_base(size_t nbr, char *base)
{
	int		i;
	int		count;

	count = 0;
	i = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = nbr * -1;
	}
	count += print_base(nbr, i, &base[0], count);
	return (count);
}
