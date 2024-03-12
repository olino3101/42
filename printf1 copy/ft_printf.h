/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:12:28 by onault            #+#    #+#             */
/*   Updated: 2024/02/18 17:26:01 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_base(size_t nbr, char *base);
int		ft_putnbr(int n, int count);
int		ft_putnbr_unsigned(unsigned int n, int count);
int		ft_putstr(char *s);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif
