#include "../includes_fractol/fractol.h"

void    fractol(t_fractol *data)
{
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
printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", data->name, data->nb_iter, data->cmouse_r, data->cmouse_i);
}
