/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 17:23:15 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./minilibx_macos/mlx.h"
#include "./libft/includes/libft.h"
#include <stdio.h>

/*
typedef struct  s_fractol
{
    float       c_r = x;
    float       c_i = y;
    float       z_r = 0;
    float       z_i = 0;
    int         iteration_max = 50;
}               t_fractol;
*/

int     main(int argc, char **argv)
{
    int         x1 = -2.1;
    int         x2 = 0.6;
    int         y1 = -1.2;
    int         y2 = 1.2;
    int         zoom = 100;
    int         iteration_max = 50;

    int         image_x = (x2 - x1) * zoom;
    int         image_y = (y2 - y1) * zoom;

    if (x = 0 && x < image_x)
    {
        if (y = 0 && y < image_y)
        {
            float       c_r = x / zoom + x1;
            float       c_i = y / zoom + y1;
            float       z_r = 0;
            float       z_i = 0;
            int        i = 0;
        }
    }


    float   tmp = z_r;
    while (((z_r * z_r + z_i * z_i)) < 4 && (i < iteration_max))
    {
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == iteration_max)
        mlx_putpixel aux coordonnees x;y

    mlx_loop(data->mlx);
}