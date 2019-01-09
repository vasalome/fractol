/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 19:50:41 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void    fractol(void *mlx_ptr, void *win_ptr, float iteration)
{
    float       x1 = -2;
    float       x2 = 2;
    float       y1 = -2;
    float       y2 = 2;
    float       screen = 200;
    int         iteration_max = iteration;

    float       image_x = (x2 - x1) * screen;
    float       image_y = (y2 - y1) * screen;

    float       c_r = 0;
    float       c_i = 0;
    float       z_r = 0;
    float       z_i = 0;
    float       i = 0;
    float       tmp = 0;

    float       x = 0;
    float       y = 0;

    while (x < image_x)
    {
        y = 0;
        while (y < image_y)
        {
            c_r = -0.75;
            c_i = -0.14;
            z_r = x / screen + x1;
            z_i = y / screen + y1;
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
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * 256 * 256 * z_r / iteration_max));
            y++;
        }
        x++;
    }
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
