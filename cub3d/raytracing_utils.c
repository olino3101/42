#include "cub3d.h"

bool verline(int x, int y1, int y2, const unsigned int color, t_data *data)
{
    int i = 0;

    while (i != y1)
    {
        mlx_put_pixel(data->img, x, i, 0x0000000);
        i++;
    }
    while (y1 <= y2)
    {
        mlx_put_pixel(data->img, x, y1, color);
        y1++;
    }
    i = y2;
    while (i != H)
    {
        mlx_put_pixel(data->img, x, i, 0x0000000);
        i++;
    }
    return true;
}
