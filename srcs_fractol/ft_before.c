#include "../minilibx_macos/mlx.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct  s_fractol
{
    double      nb_iter;
    void        *mlx;
    void        *win;
    intmax_t    x1;
    intmax_t    x2;
    intmax_t    y1;
    intmax_t    y2;
    int         color;
}               t_fractol;


typedef struct  s_coord
{
    double      x1;
    double      x2;
    double      y1;
    double      y2;
}               t_coord;

int     color_rgb_get_key(int i, double z_i)//, t_fractol *choose) // choix de couleur
{
    int r;
    int g;
    int b;

    int color = 3; // A SUPPRIMER et inserer dans une structure / get_key

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    if (color == 1) // orange
        return (r * 65536 + g * 256 + b);
    if (color == 2) // vert
        return (g * 65536 + r * 256 + b);
    if (color == 3) // bleu
        return (b * 65536 + g * 256 + r);
    if (color == 4) // stupid color
        return ((((i * 16) * 65536) + z_i * 256 * 256 * i) / z_i);
    return (0);
}

void    fractol(void *mlx_ptr, void *win_ptr, float iteration)
{
    double      x1 = -2;
    double      x2 = 2;
    double      y1 = -2;
    double      y2 = 2;
    intmax_t    zoom = 200;
    int         iteration_max = iteration;

    double      image_x = (x2 - x1) * zoom;
    double      image_y = (y2 - y1) * zoom;

    double      c_r = 0;
    double      c_i = 0;
    double      z_r = 0;
    double      z_i = 0;
    double      i = 0;
    double      tmp = 0;

    double      x = 0;
    double      y = 0;
    
    while (x < image_x)
    {
        y = 0;
        while (y < image_y)
        {
            c_r = -0.74;
            c_i = -0.14;
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
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, color_rgb_get_key(i, z_i));
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
        data_key->nb_iter += 20;
        fractol(data_key->mlx, data_key->win, data_key->nb_iter);
    }
    else if (keycode == 78)
    {
        data_key->nb_iter -= 20;
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

int     get_mouse()
{
    return (0);
}

int     main(void)
{
    t_fractol   data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "MANGE MA FRACTALE");
    data.nb_iter = 100;
    fractol(data.mlx, data.win, data.nb_iter);
    get_key(0, &data);
    get_mouse();
//    mlx_key_hook(data.win, get_key, (void *)0);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
    mlx_loop(data.mlx);
}