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

void    re_init_fract(t_fractol *data)
{
    data->nb_iter = 100;
    data->color = 1;
//    data->zoom = 100;
}

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
//      printf("\x1b[31mcode erreur: color A\n\x1b[0m");
    int r;
    int g;
    int b;

//    int color = 3; // A SUPPRIMER et inserer dans une structure / get_key

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    if (data->color == 1) // orange
    {
//        printf("\x1b[31mcode erreur: color orange - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
        return (r * 65536 + g * 256 + b);
    }
    if (data->color == 2) // vert
    {
//        printf("\x1b[31mcode erreur: color vert - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
        return (g * 65536 + r * 256 + b);
    }
    if (data->color == 3) // bleu
    {
//        printf("\x1b[31mcode erreur: color bleu - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
        return (b * 65536 + g * 256 + r);
    }
    if (data->color == 4) // stupid color
    {
//        printf("\x1b[31mcode erreur: color stupid - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
        return ((((i * 16) * 65536) + z_i * 256 * 256 * i) / z_i);
    }
    printf("\x1b[31mcode erreur: color A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    return (0);
}

void    fractol(t_fractol *data)
{
    printf("\x1b[31mcode erreur: fractol A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
/*
    double      x1 = -2;
    double      x2 = 2;
    double      y1 = -2;
    double      y2 = 2;
*/
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
            {
//                printf("\x1b[31mcode erreur: couleur black - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
                mlx_pixel_put(data->mlx, data->win, x, y, 0);
            }
            else
            {
//                printf("\x1b[31mcode erreur: couleur diffuse - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
                mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, z_i));
            }
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
    {
        dprintf(1, "KEY 69 ON\n");
        data_key->nb_iter += 20;
        dprintf(1, "KEY 69 OFF\n");
    }
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
    else if (keycode == 8)
        data_key->color = 1;
    else if (keycode == 9)
        data_key->color = 2;
    else if (keycode == 11)
        data_key->color = 3;
    else if (keycode == 45)
        data_key->color = 4;
    else if (keycode == 15)
        re_init_fract(data_key);
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("\x1b[35mcode erreur: get_mouse B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    return (0);
}
/*
int     get_mouse()
{
    printf("\x1b[33mcode erreur: get_mouse A\n\x1b[0m");
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
//    get_mouse();
 //   border_info(&data);
//    mlx_key_hook(data.win, get_key, (void *)0);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
 
    mlx_loop(data.mlx);
}