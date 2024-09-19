#include "cub3d.h"

// void input(void *param)
// {
//     t_data *data = (t_data *)param;

//     if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
//     if (mlx_is_key_down(data->mlx, MLX_KEY_W))
//     {
//         if (data->map[(int)(data->px + data->dirx * 2)][(int)(data->py)] == false)
//             data->px += data->dirx * 1.1;
//         if (data->map[(int)(data->px)][(int)(data->py + data->diry * 2)] == false)
//             data->py += data->diry * 1.1;
//     }
//     if (mlx_is_key_down(data->mlx, MLX_KEY_S))
//     {
//         int temp = (int)(data->px - data->dirx * 2);
//         if (temp >= 24 || temp <= -1 || data->py >= 24 || data->py <= 0)
//         {
//             printf("niggers\n");
//             return ;
//         }
//         temp = (int)(data->py - data->diry * 2);
//         if (temp >= 24 || temp <= -1 || data->px >= 24 || data->px <= 0)
//         {
        
//             printf("niggers\n");
//             return 0;
//         }
            
//         if (data->map[(int)(data->px - (data->dirx * 2))][(int)(data->py)] == false)
//             data->px -= data->dirx * 1.1;
//         if (data->map[(int)(data->px)][(int)(data->py - (data->diry * 2))] == false)
//             data->py -= data->diry * 1.1;
//     }
//     if (mlx_is_key_down(data->mlx, MLX_KEY_D))
//     {
//               double oldDirX = dirX;
//       dirX = dirX * cos(1) - dirY * sin(1);
//       dirY = oldDirX * sin(1) + dirY * cos(1);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(1) - planeY * sin(1);
//       planeY = oldPlaneX * sin(1) + planeY * cos(1);
//     }
//     if (mlx_is_key_down(data->mlx, MLX_KEY_A))
//     {
//               double oldDirX = dirX;
//       dirX = dirX * cos(-1) - dirY * sin(-1);
//       dirY = oldDirX * sin(-1) + dirY * cos(-1);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-1) - planeY * sin(-1);
//       planeY = oldPlaneX * sin(-1) + planeY * cos(-1);}
//     calculate_rt(data);
//     // drawPlayer(data);
// }