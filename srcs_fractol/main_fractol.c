/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 17:04:59 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
    float       c_r = x;
    float       c_i = y;
    float       z_r = 0;
    float       z_i = 0;
    int         iteration_max = 50;
    int        i = 0;
    float   tmp = z_r;
    while (((z_r * z_r + z_i * z_i)) < 4 && (i < iteration_max))
    {
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == iteration_max)
        mlx_putpixel aux coordonnees x;y
}