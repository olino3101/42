/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:16:51 by onault            #+#    #+#             */
/*   Updated: 2024/02/16 14:12:37 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(char *str, long n, int i)
{
	i--;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n > 9)
		recursive(str, n / 10, i);
	str[i] = (n % 10 + '0');
}

static int	count(long buf, int len)
{
	while (buf > 0)
	{
		buf /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		minus;
	char	*str;
	int		len;

	len = 0;
	nbr = n;
	minus = 1;
	if (nbr < 0)
	{
		len++;
		minus = -1;
	}
	nbr *= minus;
	len = count(nbr, len);
	if (nbr == 0)
		len = 1;
	str = malloc(len + 1);
	if (!(str))
		return (NULL);
	recursive(str, nbr * minus, len);
	str[len] = '\0';
	return (str);
}
