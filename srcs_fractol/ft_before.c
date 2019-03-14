void    fractol(t_fractol *data)
{
//////    printf("\x1b[31mcode erreur: fractol A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);

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
//////    printf("\x1b[31mcode erreur: fractol B - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
//////    printf("\x1b[31mcode erreur: 4emeFRACTAL - data->cmouse_r: %f - data->cmouse_i: %f\n\x1b[0m", data->cmouse_r, data->cmouse_i);
}
