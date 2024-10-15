/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:19:31 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 15:48:26 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factal.h"

static void	mandelbrot_scrollhook(double xdelta, double ydelta, void *param)
{
	static float		zoom = 1;
	t_mlx_wi_c			*struct_ptr;

	struct_ptr = (t_mlx_wi_c *)param;
	if (ydelta > 0)
		zoom *= 1.1;
	else if (ydelta < 0)
		zoom /= 1.1;
	mandelbrot(struct_ptr, zoom);
	xdelta = 0;
}

void	mandelbrot(t_mlx_wi_c *frac, float zoom)
{
	t_fractal_z	c;
	t_fractal_z	z;
	t_fractal_z	zoomco;
	int			x;
	int			y;

	z.x = 0;
	z.y = 0;
	x = -1;
	y = -1;
	zoomco.y = WIDTH / 2 * (1.0 - 1.0 / zoom);
	zoomco.x = HEIGHT / 2 * (1.0 - 1.0 / zoom);
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			c.x = ((x - zoomco.x) / (WIDTH / zoom)) * 2 - 1;
			c.y = ((y - zoomco.y) / (HEIGHT / zoom)) * 2 - 1;
			color(if_frac(z, c.x, c.y), x, y, frac->image);
		}
		y = -1;
	}
	mlx_scroll_hook(frac->mlx, &mandelbrot_scrollhook, (void *)frac);
}
