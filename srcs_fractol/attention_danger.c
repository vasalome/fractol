#include "../minilibx_macos/mlx.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct  s_fractol
{
    char        name;
    double      nb_iter;
    void        *mlx;
    void        *win;
    intmax_t    x1;
    intmax_t    x2;
    intmax_t    y1;
    intmax_t    y2;
//    double      c_r;
//    double      c_i;
//    double      z_r;
//    double      z_i;
//    double      tmp;
    intmax_t    zoom;
    int         color;
}               t_fractol;

void    init_fract(t_fractol *data)
{
    data->nb_iter = 100;
    data->color = 1;
    data->x1 = -2;
    data->x2 = 2;
    data->y1 = -2;
    data->y2 = 2;
//    data->zoom = 100;
}

int     color_rgb_get_key(int i, t_fractol *data, double z_i)//, t_fractol *choose) // choix de couleur
{
    int r;
    int g;
    int b;

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    if (data->color == 1) // orange
        return (r * 65536 + g * 256 + b);
    if (data->color == 2) // vert
        return (g * 65536 + r * 256 + b);
    if (data->color == 3) // bleu
        return (b * 65536 + g * 256 + r);
    if (data->color == 4) // stupid color
        return ((((i * 16) * 65536) + z_i * 256 * 256 * i) / z_i);
    return (0);
}



void    fractol(t_fractol *data)
{
    printf("\x1b[31mcode erreur: fractol A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    intmax_t    zoom = 200;

    int         iteration_max = data->nb_iter;

    double      image_x = (data->x2 - data->x1) * zoom;
    double      image_y = (data->y2 - data->y1) * zoom;

    double      c_r = 0;
    double      c_i = 0;
    double      z_r = 0;
    double      z_i = 0;
    double      tmp = 0;
    
    double      i = 0;

    double      x = 0;
    double      y = 0;
    
    while (x < image_x)
    {
        y = 0;
        while (y < image_y)
        {
            c_r = -0.74;
            c_i = -0.14;
            z_r = x / zoom + data->x1;
            z_i = y / zoom + data->y1;
            i = 0;
            while (((z_r * z_r + z_i * z_i)) < 4 && (i < iteration_max))
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == iteration_max)
                mlx_pixel_put(data->mlx, data->win, x, y, 0);
            else
                mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, z_i));
            y++;
        }
        x++;
    }
    printf("\x1b[31mcode erreur: fractol B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
}

int     get_key(int keycode, t_fractol *data)
{
    static t_fractol    *data_key = NULL;
    printf("\x1b[35mcode erreur: get_key A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    if (data_key == NULL)
        data_key = data;
    if (keycode == 53)
    {
        dprintf(1, "KEY ESC ON\n");
        exit(0);
    }
    else if (keycode == 69)
        data_key->nb_iter += 20;
    else if (keycode == 78)
        data_key->nb_iter -= 20;
    else if (keycode == 126)
    {
        data_key->y1 += 0.1;
        data_key->y2 += 0.1;
    }
    else if (keycode == 125)
    {
        data_key->y1 -= 0.1;
        data_key->y2 -= 0.1;
    }
    else if (keycode == 123)
    {
        data_key->x1 += 0.1;
        data_key->x2 += 0.1;
    }
    else if (keycode == 124)
    {
        data_key->x1 -= 0.1;
        data_key->x2 -= 0.1;
    }
    else if (keycode == 22)
        data_key->color = 1;
    else if (keycode == 26)
        data_key->color = 2;
    else if (keycode == 28)
        data_key->color = 3;
    else if (keycode == 25)
        data_key->color = 4;
    else if (keycode == 15)
        init_fract(data_key);
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("\x1b[35mcode erreur: get_key B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    return (0);
}
/*
int     mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
    static t_fractol    *data_mouse = NULL;
printf("\x1b[35mcode erreur: get_mouse A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
//    if (data_mouse == NULL)
//        data_mouse = data;
    if (keycode == 53)
    {
        dprintf(1, "KEY ESC ON\n");
        exit(0);
    }
    else if (keycode == 69)
    {
        dprintf(1, "KEY 69 ON\n");
        data_mouse->nb_iter += 20;
        dprintf(1, "KEY 69 OFF\n");
    }
    fractol(data_mouse);
 //   if ()
    printf("mousecode : %d\n", mousecode);
    return (0);
}

void    border_info(t_fractol *help)
{
    printf("\x1b[36mcode erreur: border_info A\n\x1b[0m");
    mlx_string_put(help->mlx, help->win, 10, 700, 0xffffff, \
		"20 iter '+' ou '-'");
    mlx_string_put(help->mlx, help->win, 10, 720, 0xffffff, \
		"next info");
    mlx_string_put(help->mlx, help->win, 600, 760, 0xffffff, \
		"example : 101");
}
*/
int     main(int argc, char **argv)
{
    t_fractol   data;

//    data.name = argv[1];
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "MANGE MA FRACTALE");
    init_fract(&data);
    fractol(&data);
    get_key(0, &data);
//    get_mouse(0, &data);
 //   border_info(&data);
//    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
 
    mlx_loop(data.mlx);
}


/*

mandelbrot
    c_r = x / zoom + data->x1;
    c_i = y / zoom + data->y1;
    z_r = 0;
    z_i = 0;  

julia
    c_r = -0.74;
    c_i = -0.14;
    z_r = x / zoom + data->x1;
    z_i = y / zoom + data->y1;

burning ship


*/