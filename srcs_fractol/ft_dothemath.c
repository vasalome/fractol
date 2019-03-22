/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dothemath.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:43:19 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 14:25:34 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
/*
void    *ft_winfred(t_bite *couilles)
{
    int         iteration_max = data->nb_iter;

    double      image_x = (data->x2 - data->x1) * data->zoom;
    double      image_y = (data->y2 - data->y1) * data->zoom;
    
    double      i = 0;

    double      x = x1;
    double      y = y1;

    while ((x < x2) && (x2 - x1) < image_x)
    {
        printf("DODU\n");
        y = 0;
        while ((y < y2) && (y2 - y1) < image_y)
        {
            printf("COCHON\n");
            ft_choice(data, x, y);
            i = 0;
            while (((data->z_r * data->z_r + data->z_i * data->z_i)) < 4 && (i < iteration_max))
            {
                if (!(ft_strcmp(data->name, "5")))
                {
                    data->tmp = data->z_r;
                    data->z_r = fabs(data->z_r * data->z_r - data->z_i * data->z_i + data->c_r);
                    data->z_i = fabs(2 * data->z_i * data->tmp + data->c_i);
                }
                else
                {
                    data->tmp = data->z_r;
                    data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
                    data->z_i = 2 * data->z_i * data->tmp + data->c_i;
                }
                i++;
            }
            if (i == iteration_max)
            {
                if(data->color_in % 2 == 1)
                    mlx_pixel_put(data->mlx, data->win, x, y, 0);
                if(data->color_in % 2 == 0)
                    mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
            }
            else
                mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, data->z_i));
            y++;
        }
        x++;
    }
    printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", data->name, data->nb_iter, data->cmouse_r, data->cmouse_i);
    return (0);
}

void    fractol(t_fractol *data)
{
    pthread_t   fred1;
    //pthread_t   fred2;
    //pthread_t   fred3;
    //pthread_t   fred4;
    //pthread_t   fred5;
    //pthread_t   fred6;
    //pthread_t   fred7;
    //pthread_t   fred8;
    //pthread_t   fred9;
    t_bite      *jojo;

    jojo = malloc(sizeof(t_bite));
    mlx_clear_window(data->mlx, data->win);
    pthread_create(&fred1, NULL, ft_winfred, jojo);
    printf("bite\n");
    //pthread_create(&fred2, NULL, ft_winfred(0, 300, 301, 600, data), NULL);
    printf("dans\n");
    //pthread_create(&fred3, NULL, ft_winfred(0, 300, 601, 900, data), NULL);
    //pthread_create(&fred4, NULL, ft_winfred(300, 600, 0, 300, data), NULL);
    //pthread_create(&fred5, NULL, ft_winfred(300, 600, 301, 600, data), NULL);
    //pthread_create(&fred6, NULL, ft_winfred(300, 600, 601, 900, data) , NULL);
    //pthread_create(&fred7, NULL, ft_winfred(600, 900, 0, 300, data) , NULL);
    //pthread_create(&fred8, NULL, ft_winfred(600, 900, 301, 600, data), NULL);
    //pthread_create(&fred9, NULL, ft_winfred(600, 900, 601, 900, data), NULL);
    printf("MAMAN\n");
    pthread_join(fred1, NULL);
    printf("papa aime ca\n");
    //pthread_join(fred2, NULL);
}
*/

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
                if (!(ft_strcmp(data->name, "5")))
                {
                    data->tmp = data->z_r;
                    data->z_r = fabs(data->z_r * data->z_r - data->z_i * data->z_i + data->c_r);
                    data->z_i = fabs(2 * data->z_i * data->tmp + data->c_i);
                }
                else
                {
                    data->tmp = data->z_r;
                    data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
                    data->z_i = 2 * data->z_i * data->tmp + data->c_i;
                }
                i++;
            }
            if (i == iteration_max)
            {
                if(data->color_in % 2 == 1)
                    mlx_pixel_put(data->mlx, data->win, x, y, 0);
                if(data->color_in % 2 == 0)
                    mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
            }
            else
                mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, data->z_i));
            y++;
        }
        x++;
    }
printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", data->name, data->nb_iter, data->cmouse_r, data->cmouse_i);
}
