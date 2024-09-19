#ifndef CUB3D_H
#define CUB3D_H

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define W 1048
#define H 1048
#define HMAP 24
#define WMAP 24
// math var of the cub3d project
typedef struct s_math {

} t_math;

// data classic windows blabla
typedef struct s_data {
    // player position on the map
    double px;
    double py;

    // direction of the player
        //determine aussi le fov
    double dirx;
    double diry;

    // the camera plane of the player
    double planex;
    double planey;


    mlx_t *mlx;
    mlx_image_t *img;

    int **map;
} t_data;

typedef struct s_rc {
    double camerax;
    double raydirx;
    double raydiry;
    int mapx;
    int mapy;
    double deltadistx;
    double deltadisty;
    double perpwalldist;
    double sidedistx;
    double sidedisty;
    int stepx;
    int stepy;
    int side;
    bool hit;
} t_rc;

extern uint32_t buf[H][W];

// void input(void *param);
bool verline(int x, int y1, int y2, const unsigned int color, t_data *data);
void calculate_rt(t_data *data);
void init_mlx(t_data *data);
t_data *init(void);
void free_ev(t_data *data);

#endif