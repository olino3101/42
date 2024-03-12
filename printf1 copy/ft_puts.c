/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:12:33 by onault            #+#    #+#             */
/*   Updated: 2024/02/18 17:23:06 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n, int count)
{
	if (n > 9)
		count = ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + '0');
	return (count + 1);
}

int	ft_putnbr(int n, int count)
{
	long	nbr;

	nbr = (int)n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		count++;
	}
	if (nbr > 9)
		count = ft_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0');
	return (count + 1);
}
