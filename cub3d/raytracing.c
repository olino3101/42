#include "cub3d.h"

void cal_sidedist(t_rc *rc, t_data *data)
{
    rc->mapx = (int)data->px;
    rc->mapy = (int)data->py;

    if (rc->raydirx < 0)
    {
        rc->stepx = -1;
        rc->sidedistx = (data->px - rc->mapx) * rc->deltadistx;
    }
    else
    {
        rc->stepx = 1;
        rc->sidedistx = (rc->mapx + 1 - data->px) * rc->deltadistx;
    }
    if (rc->raydiry < 0)
    {
        rc->stepy = -1;
        rc->sidedisty = (data->py - rc->mapy) * rc->deltadisty;
    }
    else
    {
        rc->stepy = 1;
        rc->sidedisty = (rc->mapy + 1 - data->py) * rc->deltadisty;
    }
}

void dda_process(t_rc *rc, t_data *data)
{
    while (!rc->hit)
    {
        if (rc->sidedistx < rc->sidedisty)
        {
            rc->sidedistx += rc->deltadistx;
            rc->mapx += rc->stepx;
            rc->side = 0;
        }
        else
        {
            rc->sidedisty += rc->deltadisty;
            rc->mapy += rc->stepy;
            rc->side = 1;
        }
        if (data->map[rc->mapx][rc->mapy] > 0)
            rc->hit = true;
    }
    rc->hit = false;
}
void prints_screen(t_rc *rc, t_data *data, int x)
{
    int lineheight;
    int starty;
    int endy;
    int color;

    color = 0x00FFFFFF;
    if (rc->side == 1)
        color /= 2;
    lineheight = (int)(H / rc->perpwalldist);
    starty = -lineheight / 2 + H / 2;
    if (starty < 0)
        starty = 0;
    endy = lineheight / 2 + H / 2;
    if (endy >= H)
        endy = H - 1;
    verline(x, starty, endy, color, data);
    if (x == 1)
    {
        // write(1, &start, 3);
        printf("start %i, end %i, x %i\n", starty, endy, x);
        fflush(stdout);
    }
}
void calculate_rt(t_data *data)
{
    int x;

    t_rc *rc;

    rc = malloc(sizeof(t_rc));
    x = 0;
    while (x != W)
    {
        
        // map quelle de -1 a 1
        rc->camerax = 2 * x / (double)W - 1;

        // calcul quelle direction le ray va etre
        rc->raydirx = data->dirx + data->planex * rc->camerax;
        rc->raydiry = data->diry + data->planey * rc->camerax;
        if (rc->raydirx == 0)
            rc->deltadistx = 1e30;
        else
            rc->deltadistx = fabs(1 / rc->raydirx);
        if (rc->raydiry == 0)
            rc->deltadisty = 1e30;
        else
            rc->deltadisty = fabs(1 / rc->raydiry);
        cal_sidedist(rc, data);
        // DDA process
        dda_process(rc, data);
        // calculate height
        if (rc->side == 0)
            rc->perpwalldist = rc->sidedistx - rc->deltadistx;
        else
            rc->perpwalldist = rc->sidedisty - rc->deltadisty;
        prints_screen(rc, data, x);
        rc->sidedistx = 0;
        rc->sidedisty = 0;
        x++;
    }
    free(rc);
}