/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:26:49 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 15:41:06 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTAL_H
# define FACTAL_H
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"
# define WIDTH 512
# define HEIGHT 512

typedef struct fractal_t
{
	double	x;
	double	y;
	double	z;
}	t_fractal_z;

typedef struct mlx_c_image
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		c_real;
	double		c_imag;
}	t_mlx_wi_c;

typedef struct mlx_quaternion
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		c_real;
	double		c_imag;
}	t_quater;

typedef struct coordonner_zoom
{
	int32_t	x;
	int32_t	y;
}	t_coo_zoom_t;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		check_arg_wich_fractal(int argc, char *argv[]);
bool	mlx_create(mlx_t **mlx, mlx_image_t **image);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	julia(t_mlx_wi_c *frac, float zoom);
float	ft_atoi(const char *str);
void	julia_arg(char **argv, t_mlx_wi_c *mlx_wi);
void	mandelbrot(t_mlx_wi_c *frac, float zoom);
void	color(int i, int x, int y, mlx_image_t *image);
int		if_frac(t_fractal_z z, double c_real, double c_imag);

#endif