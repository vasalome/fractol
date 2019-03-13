/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 20:18:14 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void    init_fract(t_fractol *data)
{
    data->nb_iter = 100;
    data->color = 1;
    data->x1 = -2;
    data->x2 = 2;
    data->y1 = -2;
    data->y2 = 2;
    data->zoom = 225;
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
        ft_nenufar(data, x, y);
    else
    {
        ft_usage();
        exit(0);
    }
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
    //fonction_fred(&data);
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_LENGHT, "MANGE MA FRACTALE");
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
