/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_before_first_rendu.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:43:19 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 14:33:52 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
/*
void    *ft_winfred(t_freddy *vars)
{
    int         iteration_max = vars->data->nb_iter;

    double      image_x = (vars->data->x2 - vars->data->x1) * vars->data->zoom;
    double      image_y = (vars->data->y2 - vars->data->y1) * vars->data->zoom;
    
    double      i = 0;

    double      x = vars->x1;
    double      y = vars->y1;

    while (x < vars->x2)
    {
        y = 0;
        while (y < vars->y2)
        {
            ft_choice(vars->data, vars->data->x, vars->data->y);
            i = 0;
            while (((vars->data->z_r * vars->data->z_r + vars->data->z_i * vars->data->z_i)) < 4 && (i < iteration_max))
            {
                if (!(ft_strcmp(vars->data->name, "5")))
                {
                    vars->data->tmp = vars->data->z_r;
                    vars->data->z_r = fabs(vars->data->z_r * vars->data->z_r - vars->data->z_i * vars->data->z_i + vars->data->c_r);
                    vars->data->z_i = fabs(2 * vars->data->z_i * vars->data->tmp + vars->data->c_i);
                }
                else
                {
                    vars->data->tmp = vars->data->z_r;
                    vars->data->z_r = vars->data->z_r * vars->data->z_r - vars->data->z_i * vars->data->z_i + vars->data->c_r;
                    vars->data->z_i = 2 * vars->data->z_i * vars->data->tmp + vars->data->c_i;
                }
                i++;
            }
            if (i == iteration_max)
            {
                if(vars->data->color_in % 2 == 1)
                    mlx_pixel_put(vars->data->mlx, vars->data->win, x, y, 0);
                if(vars->data->color_in % 2 == 0)
                    mlx_pixel_put(vars->data->mlx, vars->data->win, x, y, 0xFFFFFF);
            }
            else
                mlx_pixel_put(vars->data->mlx, vars->data->win, x, y, color_rgb_get_key(i, vars->data, vars->data->z_i));
            y++;
        }
        x++;
    }
    printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", vars->data->name, vars->data->nb_iter, vars->data->cmouse_r, vars->data->cmouse_i);
    return (0);
}

void    init_fred1(t_freddy *vars)
{
    printf("ALOHA 1\n");
    vars->x1 = 0;
    vars->x2 = 300;
    vars->y1 = 0;
    vars->y2 = 300;
}

void    init_fred2(t_freddy *vars)
{
    vars->x1 = 0;
    vars->x2 = 300;
    vars->y1 = 301;
    vars->y2 = 600;
}

void    init_fred3(t_freddy *vars)
{
    printf("ALOHA 3\n");
    vars->x1 = 0;
    vars->x2 = 300;
    vars->y1 = 601;
    vars->y2 = 900;
}

void    init_fred4(t_freddy *vars)
{
    printf("ALOHA 4\n");
    vars->x1 = 301;
    vars->x2 = 600;
    vars->y1 = 0;
    vars->y2 = 300;
}

void    init_fred5(t_freddy *vars)
{
    printf("ALOHA 5\n");
    vars->x1 = 301;
    vars->x2 = 600;
    vars->y1 = 301;
    vars->y2 = 600;
}

void    init_fred6(t_freddy *vars)
{
    printf("ALOHA 6\n");
    vars->x1 = 301;
    vars->x2 = 600;
    vars->y1 = 601;
    vars->y2 = 900;
}

void    init_fred7(t_freddy *vars)
{
    printf("ALOHA 7\n");
    vars->x1 = 601;
    vars->x2 = 900;
    vars->y1 = 0;
    vars->y2 = 300;
}

void    init_fred8(t_freddy *vars)
{
    printf("ALOHA 8\n");
    vars->x1 = 601;
    vars->x2 = 900;
    vars->y1 = 301;
    vars->y2 = 600;
}

void    init_fred9(t_freddy *vars)
{
    printf("ALOHA 9\n");
    vars->x1 = 601;
    vars->x2 = 900;
    vars->y1 = 601;
    vars->y2 = 900;
}

void    fractol(t_fractol *data)
{
    pthread_t   fred1;
    pthread_t   fred2;
    pthread_t   fred3;
    pthread_t   fred4;
    pthread_t   fred5;
    pthread_t   fred6;
    pthread_t   fred7;
    pthread_t   fred8;
    pthread_t   fred9;
    t_freddy      vars;

    mlx_clear_window(data->mlx, data->win);
printf("PHASE 1\n");
    init_fred1(&vars);
printf("HOLO 1\n");
    pthread_create(&fred1, NULL, (void *)ft_winfred, &vars);
printf("PHASE 2\n");
    init_fred2(&vars);
printf("HOLO 2\n");
    pthread_create(&fred2, NULL, (void *)ft_winfred, &vars);
printf("PHASE 3\n");
    init_fred3(&vars);
printf("HOLO 3\n");
    pthread_create(&fred3, NULL, (void *)ft_winfred, &vars);
printf("PHASE 4\n");
    init_fred4(&vars);
    pthread_create(&fred4, NULL, (void *)ft_winfred, &vars);
printf("PHASE 5\n");
    init_fred5(&vars);
    pthread_create(&fred5, NULL, (void *)ft_winfred, &vars);
printf("PHASE 6\n");
    init_fred6(&vars);
    pthread_create(&fred6, NULL, (void *)ft_winfred, &vars);
printf("PHASE 7\n");
    init_fred7(&vars);
    pthread_create(&fred7, NULL, (void *)ft_winfred, &vars);
printf("PHASE 8\n");
    init_fred8(&vars);
    pthread_create(&fred8, NULL, (void *)ft_winfred, &vars);
printf("PHASE 9\n");
    init_fred9(&vars);
    pthread_create(&fred9, NULL, (void *)ft_winfred, &vars);
printf("PHASE 10\n");
    pthread_join(fred1, NULL);
    pthread_join(fred2, NULL);
    pthread_join(fred3, NULL);
    pthread_join(fred4, NULL);
    pthread_join(fred5, NULL);
    pthread_join(fred6, NULL);
    pthread_join(fred7, NULL);
    pthread_join(fred8, NULL);
    pthread_join(fred9, NULL);
printf("AFTER JOIN\n");
}

*/











/*

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIN_WIDTH && data->y < WIN_LENGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIN_WIDTH * y + x * 4, &color, sizeof(int));
	}
}

void    fractol(t_fractol *data)
{
    int         iteration_max = data->nb_iter;

    double      image_x = (data->x2 - data->x1) * data->zoom;
    double      image_y = (data->y2 - data->y1) * data->zoom;
    
    double      i = 0;

    data->x = 0;
    data->y = 0;
    mlx_clear_window(data->mlx, data->win);
    while (data->x < image_x)
    {
        data->y = 0;
        while (data->y < image_y)
        {
            ft_choice(data, data->x, data->y);
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
                    put_pxl_to_img(data, data->x, data->y, 0);
                if(data->color_in % 2 == 0)
                    put_pxl_to_img(data, data->x, data->y, 0xFFFFFF);
            }
            else
                put_pxl_to_img(data, data->x, data->y, color_rgb_get_key(i, data, data->z_i));
            data->y++;
        }
        data->x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", data->name, data->nb_iter, data->cmouse_r, data->cmouse_i);
}


*/





static void	calcul_burningship(t_fractol *data)
{
	data->tmp = data->z_r;
	data->z_r = fabs(data->z_r * data->z_r - data->z_i * data->z_i + data->c_r);
	data->z_i = fabs(2 * data->z_i * data->tmp + data->c_i);
}

static void	calcul_fractals(t_fractol *data)
{
	data->tmp = data->z_r;
	data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
	data->z_i = 2 * data->z_i * data->tmp + data->c_i;
}

static void	calcul_color_in(t_fractol *data, double x, double y)
{
	if (data->color_in % 2 == 1)
		mlx_pixel_put(data->mlx, data->win, x, y, 0);
	if (data->color_in % 2 == 0)
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

static void	calcul_fractol(t_fractol *data, double x, double y, double i)
{
	ft_choice(data, x, y);
			i = 0;
			while (((data->z_r * data->z_r + data->z_i * data->z_i)) < 4 && (i < data->nb_iter))
			{
				if (!(ft_strcmp(data->name, "5")))
					calcul_burningship(data);
				else
					calcul_fractals(data);
				i++;
			}
			if (i == data->nb_iter)
				calcul_color_in(data, x, y);
			else
				mlx_pixel_put(data->mlx, data->win, x, y, color_rgb_get_key(i, data, data->z_i));
}

void		fractol(t_fractol *data)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	x = 0;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	mlx_clear_window(data->mlx, data->win);
	while (x < data->image_x)
	{
		y = 0;
		while (y < data->image_y)
		{
			calcul_fractol(data, x, y, i);
			y++;
		}
		x++;
	}
}