#include "../minilibx_macos/mlx.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
    intmax_t    x;
    intmax_t    y;
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
    data->zoom = 200;
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

    int         iteration_max = data->nb_iter;

    double      image_x = (data->x2 - data->x1) * data->zoom;
    double      image_y = (data->y2 - data->y1) * data->zoom;

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
            z_r = x / data->zoom + data->x1;
            z_i = y / data->zoom + data->y1;
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
    else if (keycode == 8)
        data_key->color = 1;
    else if (keycode == 9)
        data_key->color = 2;
    else if (keycode == 11)
        data_key->color = 3;
    else if (keycode == 45)
        data_key->color = 4;
    else if (keycode == 15)
        init_fract(data_key);
    //else if (keycode == 25)
        //hide_info;
    else if (keycode == 6)
    {
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom * 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom * 1.3));
        data_key->zoom *= 1.3;
        data_key->nb_iter += 10;
    }
    else if (keycode == 7)
    { // Maybe : Ajouter un blocage pour empecher le zoom > 0 sinon segfault
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom / 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom / 1.3));
        data_key->zoom /= 1.3;
        data_key->nb_iter -= 10;
    }
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("\x1b[35mcode erreur: get_key B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    return (0);
}
/*
int     mouse(int mousecode, int x, int y, t_fractol *data)
{
    static t_fractol    *data_mouse = NULL;
printf("\x1b[35mcode erreur: get_mouse A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
//    if (data_mouse == NULL)
//        data_mouse = data;
    if (mousecode == 4 || mousecode == 1)
    {
        data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom * 1.3));
        data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom * 1.3));
        data_mouse->zoom *= 1.3;
        data_mouse->nb_iter++;
    }
    else if (mousecode == 5 || mousecode == 2)
    {
        data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom / 1.3));
        data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom / 1.3));
        data_mouse->zoom /= 1.3;
        data_mouse->nb_iter--;
    }
    fractol(data_mouse);
    printf("mousecode : %d\n", mousecode);
    return (0);
}
*/
void    border_info(t_fractol *help)
{
    printf("\x1b[36mcode erreur: border_info A\n\x1b[0m");
    mlx_string_put(help->mlx, help->win, 10, 700, 0xffffff, \
		"c-v-b-n : orange-vert-bleu-glitch");
    mlx_string_put(help->mlx, help->win, 10, 720, 0xffffff, \
		"r : reboot");
    //mlx_string_put(help->mlx, help->win, 10, 740, 0xffffff, \
		"h : hide text");
    mlx_string_put(help->mlx, help->win, 600, 760, 0xffffff, \
		"example : 101");
}

int		ft_usage(void)
{
	write(1, "How to use ?              \n", 27);
    write(1, "\n", 1);
    write(1, "Exemple : ./fractol 4     \n", 27);
    write(1, ". 1 : Mandelbrot          \n", 27);
    write(1, ". 2 : Julia               \n", 27);
    write(1, ". 3 : Burningship         \n", 27);
    write(1, ". 4 : Tapis Sierpinski    \n", 27);
    write(1, ". 5 : Triangle Sierpinski \n", 27); // ou fougere
    write(1, ". 6 : Fractale Perso 1    \n", 27);
    write(1, ". 7 : Fractale Perso 2    \n", 27);
    write(1, ". 8 : Fractale Perso 3    \n", 27);
    write(1, ". 9 : Fractale Perso 4    \n", 27);
	return (64);
}

int     red_cross()
{
    exit(0);
    return (0);
}

int     main(int argc, char **argv)
{
    t_fractol   data;

    if (argc != 2)
    {
        ft_usage();
        exit(0);
    }
    data.name = *argv[1];
    printf("data.name: %c\n", data.name);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "MANGE MA FRACTALE");
    init_fract(&data);
    fractol(&data);
    get_key(0, &data);
    mlx_hook(data.win, 17, 0, red_cross, (void *)0);
//    mlx_mouse_hook(0, mouse, &data);
    border_info(&data);
//    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
 
    mlx_loop(data.mlx);
}


/*

mandelbrot
    c_r = x / data->zoom + data->x1;
    c_i = y / data->zoom + data->y1;
    z_r = 0;
    z_i = 0;  

julia
    c_r = -0.74;
    c_i = -0.14;
    z_r = x / data->zoom + data->x1;
    z_i = y / data->zoom + data->y1;

burning ship


*/