/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:14:50 by onault            #+#    #+#             */
/*   Updated: 2024/02/18 17:28:24 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_pxx(unsigned long adr, char c, int count)
{
	if (c == 'p')
		count = ft_putstr("0x");
	if (c == 'X')
		count = ft_putnbr_base(adr, "0123456789ABCDEF");
	else
		count += ft_putnbr_base(adr, "0123456789abcdef");
	return (count);
}

static int	wichpercent(va_list args, const char *str, size_t i)
{
	int	count;

	count = 0;
	if (str[i] == '%')
	{
		ft_putchar(str[i]);
		count++;
	}
	else if (str[i] == 'u')
		count = ft_putnbr_unsigned(va_arg(args, unsigned int), 0);
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_putnbr(va_arg(args, long), 0);
	else if (str[i] == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'x' || str[i] == 'X')
		count = ft_pxx(va_arg(args, unsigned int), str[i], 0);
	else if (str[i] == 'p')
		count = ft_pxx(va_arg(args, unsigned long), str[i], 0);
	else if (str[i] == 'c')
	{
		ft_putchar((unsigned char)(va_arg(args, int)));
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += wichpercent(args, str, i + 1);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}
