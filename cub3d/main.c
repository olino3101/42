#include "cub3d.h"

void drawPlayer(t_data *data) {
    for (int i = 0 ; i < HEIGHT; i++) {
        for (int j = 0;j < WIDTH; j++) {
        if (data->px >= i - 4 && data->px <= i + 4 && data->py >= j - 4 && data->py <= j + 4 )
            mlx_put_pixel(data->img, i, j, 0x00FFFFFF); 
        else
            mlx_put_pixel(data->img, i, j, 0xFFFF00); }}
}

void input(void *param)
{
    t_data *data = (t_data *)param;

    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
    if (mlx_is_key_down(data->mlx, MLX_KEY_W))
        data->py += 5;
    if (mlx_is_key_down(data->mlx, MLX_KEY_S))
        data->py -= 5;
    if (mlx_is_key_down(data->mlx, MLX_KEY_D))
        data->px += 5;
    if (mlx_is_key_down(data->mlx, MLX_KEY_A))
        data->px -= 5;
    drawPlayer(data);
}


int main()
{
    
    t_data *data;
    data = init();
    int gray = 10 % 255;
    for (int i = 0 ; i < HEIGHT; i++) {
        for (int j = 0;j < WIDTH; j++) {
            mlx_put_pixel(data->img, i, j, (gray << 16) | (gray << 8) | gray); }}
    drawPlayer(data);
    mlx_loop_hook(data->mlx, input, data);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    // free_ev(data);
    return 0;
}
