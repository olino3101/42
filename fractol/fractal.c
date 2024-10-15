/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:40:56 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 12:13:19 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factal.h"

bool	mlx_create(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!*mlx)
		return (false);
	*image = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (false);
	}
	mlx_image_to_window(*mlx, *image, 0, 0);
	if (!(mlx_image_to_window(*mlx, *image, 0, 0)) || !*image)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

int	if_frac(t_fractal_z z, double c_real, double c_imag)
{
	int			i;
	t_fractal_z	temp;

	i = 0;
	while ((z.y * z.y + c_imag) + (z.x * z.x + c_real) < 4 && i != 250)
	{
		temp = z;
		z.x = temp.x * temp.x - temp.y * temp.y + c_real;
		z.y = 2 * temp.y * temp.x + c_imag;
		i++;
	}
	return (i);
}

void	color(int i, int x, int y, mlx_image_t *image)
{
	uint32_t	color;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		red;

	if (i == 250)
		color = 0x000000;
	else
	{
		red = i * 45;
		green = i * 20;
		blue = i * 80;
		color = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
	}
	mlx_put_pixel(image, x, y, color);
}

static void	handle_key(void *param)
{
	t_mlx_wi_c	*frac;

	frac = (t_mlx_wi_c *)param;
	if (mlx_is_key_down(frac->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(frac->mlx);
		mlx_close_window(frac->mlx);
		free(frac);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	int					fractal_type;
	t_mlx_wi_c			*frac;

	frac = malloc(sizeof(t_mlx_wi_c));
	fractal_type = check_arg_wich_fractal(argc, argv);
	if (fractal_type == 0)
		return (EXIT_FAILURE);
	else if (mlx_create(&frac->mlx, &frac->image) == false)
		return (EXIT_FAILURE);
	else if (fractal_type == 1)
		julia_arg(argv, frac);
	else if (fractal_type == 2)
		mandelbrot(frac, 1);
	mlx_loop_hook(frac->mlx, &handle_key, frac);
	mlx_loop(frac->mlx);
}
