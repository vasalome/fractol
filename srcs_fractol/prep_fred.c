void    *ft_winfred(t_freddy *vars)
{
    int         iteration_max = vars->data->nb_iter;

    double      image_x = (vars->data->x2 - vars->data->x1) * vars->data->zoom;
    double      image_y = (vars->data->y2 - vars->data->y1) * vars->data->zoom;
    
    double      i = 0;

    double      x = vars->x1;
    double      y = vars->y1;

    while ((x < x2) && (x2 - x1) < image_x)
    {
        printf("DODU\n");
        y = 0;
        while ((y < y2) && (y2 - y1) < image_y)
        {
            printf("COCHON\n");
            ft_choice(data, x, y);
            i = 0;
            while (((vars->data->z_r * vars->data->z_r + vars->data->z_i * vars->data->z_i)) < 4 && (i < iteration_max))
            {
                if (!(ft_strcmp(vars->data->name, "5")))
                {
                    vars->data->tmp = data->z_r;
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
    printf("\x1b[31mdata.name:\x1b[0m %s ; \x1b[31mnb_iter:\x1b[0m %f ; \x1b[31mdata.cmouse_r:\x1b[0m %f ; \x1b[31mdata.cmouse_i:\x1b[0m %f\n", data->name, data->nb_iter, data->cmouse_r, data->cmouse_i);
    return (0);
}

initfred_1(t_freddy vars)
{
    vars->x1 = 0;
    vars->x2 = 300;
    vars->y1 = 0;
    vars->y2 = 300;
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
    t_freddy      *vars;

    mlx_clear_window(data->mlx, data->win);

    initfred_1(vars);
    pthread_create(&fred1, NULL, ft_winfred, vars);
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