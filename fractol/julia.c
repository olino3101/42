/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:06:20 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 15:48:25 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factal.h"

static void	julia_scrollhook(double xdelta, double ydelta, void *param)
{
	static float		zoom = 1;
	t_mlx_wi_c			*struct_ptr;

	struct_ptr = (t_mlx_wi_c *)param;
	if (ydelta > 0)
		zoom *= 1.1;
	else if (ydelta < 0)
		zoom /= 1.1;
	julia(struct_ptr, zoom);
	xdelta = 0;
}

void	julia(t_mlx_wi_c *frac, float zoom)
{
	t_fractal_z	z;
	t_fractal_z	step;
	int			x;
	int			y;

	x = -1;
	y = -1;
	step.y = WIDTH / 2 * (1.0 - 1.0 / zoom);
	step.x = HEIGHT / 2 * (1.0 - 1.0 / zoom);
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			z.x = ((x - step.x) / (WIDTH / zoom)) * 2 - 1;
			z.y = ((y - step.y) / (HEIGHT / zoom)) * 2 - 1;
			color(if_frac(z, frac->c_real, frac->c_imag), x, y, frac->image);
		}
		y = -1;
	}
	mlx_scroll_hook(frac->mlx, &julia_scrollhook, (void *)frac);
}

void	julia_arg(char **argv, t_mlx_wi_c *frac)
{
	frac->c_real = ft_atoi(argv[2]);
	frac->c_imag = ft_atoi(argv[3]) * 10;
	julia(frac, 1);
}
