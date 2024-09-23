#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <math.h>

# define HTEXT
# define WTEXT
# define W 1048
# define H 1048
# define WMAP 12
# define HMAP 12

# define A "./img/a.png"
// dirx 0 diry 1, planx 0.66 plany 0
# define EA "./img/brick.png"
// dirx 0 diry -1, planx -0.66 plany 0
# define WE "./img/wood.png"
# define NO "./img/plank.png"
// dirx 1 diry 0, planx 0 plany -0.66
# define SO "./img/rock.png"
// math var of the cub3d project

typedef struct s_color
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint32_t	color;
}	t_color;

typedef struct s_print_tex
{
	int		tex_i;
	int		side;
	int		x;
	int		texx;
	int		lineheight;
	double	perpwalldist;
}	t_print_tex;

typedef struct s_data
{
	double			px;
	double			py;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	float			speed;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture[4];
	int				**map;
}	t_data;

typedef struct s_rc
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		side;
	bool	hit;
}	t_rc;

t_print_tex	init_print_tex(t_rc *rc, int x, t_data *data);
void		input(void *param);
void		verline(t_print_tex texs, int y1, int y2, t_data *data);
void		rt(t_data *data);
t_data		*init(void);
void		free_ev(t_data *data);

#endif