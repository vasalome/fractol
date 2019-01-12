/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:06:26 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int     ft_choose(int argc, char **argv, t_fractol data)
{
    int     i;

    i = 1;
    while (i < argc - 1)
    {
        if (strcmp(argv[i], "1") == 0)
            data->c_fractol = mandelbrot;
            //FONCTION POUR LA FAIRE
        if (strcmp(argv[i], "2") == 0)
            data->c_fractol = julia;
        if (strcmp(argv[i], "3") == 0)
            data->c_fractol = julia_2;
        if (strcmp(argv[i], "4") == 0)
            data->c_fractol = burningship;
        if (strcmp(argv[i], "5") == 0)
            data->c_fractol = tapis_sierpinski;
        if (strcmp(argv[i], "6") == 0)
            data->c_fractol = triangle_sierpinski;
        if (strcmp(argv[i], "7") == 0)
            data->c_fractol = circulaire; //fractale circulaire ou remplacer par fougere
        if (strcmp(argv[i], "8") == 0)
            data->c_fractol = random; //ajouter valeur random
        if (strcmp(argv[i], "9") == 0)
            data->c_fractol = glitch; //ajouter valeur et couleur random
        if (data->c_fractol == NULL)
            //ERREUR ARGUMENT
        i++;
    }
}

int     main(int argc, char **argv)
{
    t_fractol   data;

    if (argc == 1)
        //FONCTION USAGE 
    else
        ft_choose(argc, **argv, data);

FAIRE LE RESTE DANS UNE AUTRE FONCTION POUR CHOOSE
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_LENGHT, "MANGE MA FRACTALE");
    data.nb_iter = 100;
    ft_fractol(data.mlx, data.win, data.nb_iter);
    get_key(0, &data);
//    mlx_key_hook(data.win, get_key, (void *)0);
    mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
    mlx_loop(data.mlx);
    return (0);
}
