#include "../minilibx_macos/mlx.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_fractol
{
    float       nb_iter;
    void        *mlx;
    void        *win;
    float       x1;
    float       x2;
    float       y1;
    float       y2;
}               t_fractol;

/*
typedef struct  s_coord
{
    float       x1;
    float       x2;
    float       y1;
    float       y2;
}               t_coord;
*/

void    fractol(void *mlx_ptr, void *win_ptr, float iteration)
{
    float       x1 = -2;
    float       x2 = 2;
    float       y1 = -2;
    float       y2 = 2;
    float       zoom = 200;
    int         iteration_max = iteration;

    float       image_x = (x2 - x1) * zoom;
    float       image_y = (y2 - y1) * zoom;

    float       c_r = 0;
    float       c_i = 0;
    float       z_r = 0;
    float       z_i = 0;
    float       i = 0;
    float       tmp = 0;

    float       x = 0;
    float       y = 0;

    int         randomize = rand() % 2;
    int         randomize2 = rand() % 2;

    while (x < image_x)
    {
        y = 0;
        while (y < image_y)
        {
            c_r = -1.762;//-0.75;//randomize;
            c_i = -0.028 * i;//-0.14;//randomize2;
            z_r = x / zoom + x1;
            z_i = y / zoom + y1;
            i = 0;
            while (((z_r * z_r + z_i * z_i)) < 4 && (i < iteration_max))
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == iteration_max)
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0);
            else
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * 256 * 256 * 256 / iteration_max));
            y++;
        }
        x++;
    }
}

int     get_key(int keycode, t_fractol *data)
{
    static t_fractol    *data_key = NULL;

    if (data_key == NULL)
        data_key = data;
    if (keycode == 53)
        exit(0);
    else if (keycode == 69)
    {
        data_key->nb_iter += 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 78)
    {
        data_key->nb_iter -= 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 126)
    {
        data_key->nb_iter += 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 125)
    {
        data_key->nb_iter += 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 123)
    {
        data_key->nb_iter += 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 124)
    {
        data_key->nb_iter += 1;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    printf("keycode : %d\n", keycode);
    return (0);
}

int     main(void)
{
    t_fractol   data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1250, 1250, "MANGE MA FRACTALE");
    data.nb_iter = 100;
    fractol(data.mlx, data.win, data.nb_iter);
    get_key(0, &data);
//    mlx_key_hook(data.win, get_key, (void *)0);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
    mlx_loop(data.mlx);
}