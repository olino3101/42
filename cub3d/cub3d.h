#ifndef CUB3D_H
#define CUB3D_H

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1048
#define HEIGHT 1048
// math var of the cub3d project
typedef struct s_math {

} t_math;

// data classic windows blabla
typedef struct s_data {
    float px;
    float py;
    mlx_t *mlx;
    mlx_image_t *img;
    int **map;
    int mapx;
    int mapy;
} t_data;

void init_mlx(t_data *data);
t_data *init(void);
void free_ev(t_data *data);

#endif