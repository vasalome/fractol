#include "../minilibx_macos/mlx.h"
//#include "../libX11/include/X11/Xlib.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <Tk/X11/X.h>

typedef struct  s_fractol
{
    char        *name;
    double      nb_iter;
    void        *mlx;
    void        *win;
    intmax_t    x1;
    intmax_t    x2;
    intmax_t    y1;
    intmax_t    y2;
    intmax_t    x;
    intmax_t    y;
    double      c_r;
    double      c_i;
    double      z_r;
    double      z_i;
    double      cmouse_r;
    double      cmouse_i;
    double      tmp;
    intmax_t    zoom;
    int         color;
}               t_fractol;

int		ft_usage(void)
{
    write(1, "\n", 1);
	write(1, "How to use ?              \n", 27);
    write(1, "\n", 1);
    write(1, "Exemple : ./fractol 4     \n", 27);
    write(1, ". 1 : Mandelbrot          \n", 27);
    write(1, ". 2 : Julia               \n", 27);
    write(1, ". 3 : Burningship         \n", 27);
    write(1, ". 4 : Tapis Sierpinski    \n", 27);
    write(1, ". 5 : Triangle Sierpinski \n", 27); // ou fougere
    write(1, ". 6 : Fractale Portail    \n", 27);
    write(1, ". 7 : Fractale Tornado    \n", 27);
    write(1, ". 8 : Fractale Perso 3    \n", 27);
    write(1, ". 9 : Fractale Perso 4    \n", 27);
    write(1, "\n", 1);
	return (64);
}

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

void    ft_mandelbrot(t_fractol *data, double x, double y)
{
    data->c_r = x / data->zoom + data->x1;
    data->c_i = y / data->zoom + data->y1;
    data->z_r = 0;
    data->z_i = 0;
}

void    ft_julia(t_fractol *data, double x, double y)
{
    data->c_r = -0.74;
    data->c_i = -0.14;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_burningship(t_fractol *data, double x, double y)
{
    data->c_r = -1.762;
    data->c_i = -0.028; //* i;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_tapis(t_fractol *data, double x, double y)
{/*
    int     i;

    i = 0;
    x *= data->zoom;
    y *= data->zoom;
    while (i < 100)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);*/
}

void    ft_triangle(t_fractol *data, double x, double y)
{
    data->c_r = data->cmouse_r;
    data->c_i = data->cmouse_i;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_portail(t_fractol *data, double x, double y)
{
    data->c_r = 0;
    data->c_i = x / data->zoom + data->x1;
    data->z_r = 0;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_tornado(t_fractol *data, double x, double y)
{
    data->c_r = 0.369697;
    data->c_i = 0.312121;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_perso3(t_fractol *data, double x, double y)
{
    data->c_r = data->cmouse_r;
    data->c_i = data->cmouse_i;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_perso4(t_fractol *data, double x, double y)
{
    data->c_r = data->cmouse_r;
    data->c_i = data->cmouse_i;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_choice(t_fractol *data, double x, double y)
{
    if (!(strcmp(data->name, "1"))) // NE PAS OUBLIER DE MODIFIER LES STRCMP PAR MA FONCTION
        ft_mandelbrot(data, x, y);
    else if (!(strcmp(data->name, "2")))
        ft_julia(data, x, y);
    else if (!(strcmp(data->name, "3")))
        ft_burningship(data, x, y);
    else if (!(strcmp(data->name, "4")))
        ft_tapis(data, x, y);
    else if (!(strcmp(data->name, "5")))
        ft_triangle(data, x, y);
    else if (!(strcmp(data->name, "6")))
        ft_portail(data, x, y);
    else if (!(strcmp(data->name, "7")))
        ft_tornado(data, x, y);
    else if (!(strcmp(data->name, "8")))
        ft_perso3(data, x, y);
    else if (!(strcmp(data->name, "9")))
        ft_perso4(data, x, y);
    else
    {
        ft_usage();
        exit(0);
    }
}

void    fractol(t_fractol *data)
{
    printf("\x1b[31mcode erreur: fractol A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);

    int         iteration_max = data->nb_iter;

    double      image_x = (data->x2 - data->x1) * data->zoom;
    double      image_y = (data->y2 - data->y1) * data->zoom;
    
    double      i = 0;

    double      x = 0;
    double      y = 0;
    mlx_clear_window(data->mlx, data->win);
    while (x < image_x)
    {
        y = 0;
        while (y < image_y)
        {
            ft_choice(data, x, y);
            i = 0;
            while (((data->z_r * data->z_r + data->z_i * data->z_i)) < 4 && (i < iteration_max))
            {
                data->tmp = data->z_r;
                data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
                data->z_i = 2 * data->z_i * data->tmp + data->c_i;

                
                //data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r; TEST burningship
                //data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_r;
                //data->z_r = data->tmp;


                i++;
            }
            if (i == iteration_max)
                mlx_pixel_put(data->mlx, data->win, x, y, 0);
            else
                mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, data->z_i));
            y++;
        }
        x++;
    }
    printf("\x1b[31mcode erreur: fractol B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
    printf("\x1b[31mcode erreur: 4emeFRACTAL - data->cmouse_r: %f - data->cmouse_i: %f\n\x1b[0m", data->cmouse_r, data->cmouse_i);
}

int     get_key(int keycode, t_fractol *data)
{
    static t_fractol    *data_key = NULL;
    printf("code erreur: get_key A - ENTRER\n");
    if (data_key == NULL)
        data_key = data;
    if (keycode == 53)
        exit(0);
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
    //else if (keycode == 4)
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
    else if (keycode == 18)
        data_key->name = "1";
    else if (keycode == 19)
        data_key->name = "2";
    else if (keycode == 20)
        data_key->name = "3";
    else if (keycode == 21)
        data_key->name = "4";
    else if (keycode == 23)
        data_key->name = "5";
    else if (keycode == 22)
        data_key->name = "6";
    else if (keycode == 26)
        data_key->name = "7";
    else if (keycode == 28)
        data_key->name = "8";
    else if (keycode == 25)
        data_key->name = "9";
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("code erreur: get_key A - SORTIE\n");
    return (0);
}

int     get_my_mouse(int x, int y, t_fractol *data)
{
    printf("code erreur: get_my_mouse A - SORTIE\n");
    static t_fractol *data_mouse = NULL;
    double  x1;
    double  x2;

    if (data_mouse == NULL)
        data_mouse = data;
    x1 = x;
    x2 = y;
    data_mouse->cmouse_r = x1 / 660;
    data_mouse->cmouse_i = x2 / 660;
    printf("code erreur: get_my_mouse IN - SORTIE\n");
    fractol(data_mouse);
    printf("code erreur: get_my_mouse B - SORTIE\n");
    return (0);
}

int     get_key_mouse(int mousecode, int x, int y, t_fractol *data)
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

void	ft_whats_my_buttons(void)
{
    write(1, "\n", 1);
	write(1, "Interaction ->            \n", 27);
    write(1, "\n", 1);
    write(1, "Colors :                  \n", 27);
    write(1, ". C : Base orange         \n", 27);
    write(1, ". V : Base verte          \n", 27);
    write(1, ". B : Base bleue          \n", 27);
    write(1, ". N : Surprise            \n", 27);
    write(1, "\n", 1);
    write(1, "Options Zoom :            \n", 27);
    write(1, ". Z - Souris 1 : Zoom In  \n", 27);
    write(1, ". X - Souris 2 : Zoom Out \n", 27);
    write(1, ". Or use mouse wheel      \n", 27);
    write(1, "\n", 1);
    write(1, "Mouvements :              \n", 27);
    write(1, "Use Arrows                \n", 27);
    write(1, "\n", 1);
    write(1, "Autres     :              \n", 27);
    write(1, ". R : Reset               \n", 27);
    write(1, ". 1-9 : Change ur fractal \n", 27);
    write(1, "\n", 1);
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
    data.name = argv[1];
    printf("data.name: %s\n", data.name);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "MANGE MA FRACTALE");
    init_fract(&data);
    fractol(&data);
    ft_whats_my_buttons();
    get_key(0, &data);
    //get_key_mouse(0, 0, 0, &data);
    get_my_mouse(0, 0, &data);
    mlx_hook(data.win, 17, 0, red_cross, (void *)0);
//    mlx_mouse_hook(0, mouse, &data);
    mlx_hook(data.win, MotionNotify, PointerMotionMask, get_my_mouse, (void *)0);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
 
    mlx_loop(data.mlx);
}