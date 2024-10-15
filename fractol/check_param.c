/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:20:41 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 15:35:12 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factal.h"

static int	wich_fractal(char **argv)
{
	int	cmp;

	cmp = ft_strncmp(*argv, "Julia", sizeof(*argv));
	if (cmp == 0)
		return (1);
	cmp = ft_strncmp(*argv, "Mandelbrot", sizeof(*argv));
	if (cmp == 0)
		return (2);
	return (0);
}

int	erreur_mandel(char **argv)
{
	if (argv[2])
	{
		write(2, "la Mandelbrot ne prend pas d'argument\n", 38);
		return (0);
	}
	return (2);
}

int	check_arg_wich_fractal(int argc, char *argv[])
{
	if (argc <= 1 || argc > 4)
	{
		write(2, "not the right number of argument\nJulia or Mandelbrot", 52);
		write(2, "\nif you choose Julia it must take 2", 36);
		write(2, "numbers between -2 and 2", 24);
		return (0);
	}
	if (wich_fractal(&argv[1]) == 1)
	{
		if (!argv[2] || !argv[3])
		{
			write(2, "not the right number of argument\n", 33);
			write(2, "Julia must take 2 numbers between -2 and 2\n", 42);
			return (0);
		}
		return (1);
	}
	else if (wich_fractal(&argv[1]) == 2)
		return (erreur_mandel(argv));
	write(2, "not the right argument\nJulia or Mandelbrot\n", 43);
	write(2, "if you choose Julia it must take 2 numbers between -2 and 2", 59);
	return (0);
}
