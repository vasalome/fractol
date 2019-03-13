/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 18:27:34 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
#include "../includes_fractol/keys.h"

int     get_my_mouse(int x, int y, t_fractol *data)
{
    printf("code erreur: get_my_mouse A - SORTIE\n");
    static t_fractol *data_mouse = NULL;
    double  x1;
    double  x2;

    if (data_mouse == NULL)
        data_mouse = data;
    if (!(strcmp(data_mouse->name, "2")))
    {
        x1 = x;
        x2 = y;
        data_mouse->cmouse_r = x1 / 660;
        data_mouse->cmouse_i = x2 / 660;
        printf("code erreur: get_my_mouse IN - SORTIE\n");
        fractol(data_mouse);
        printf("code erreur: get_my_mouse B - SORTIE\n");
    }
    return (0);
}

int     get_key_mouse(int mousecode, int x, int y, t_fractol *data)
{
    static t_fractol    *data_mouse = NULL;
printf("\x1b[35mcode erreur: get_mouse A - nb_iter: %f - color: %d\n\x1b[0m", data->nb_iter, data->color);
//    if (data_mouse == NULL)
//        data_mouse = data;
    if (mousecode == 4 || mousecode == 1)
    {
        data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom * 1.3));
        data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom * 1.3));
        data_mouse->zoom *= 1.3;
        data_mouse->nb_iter++;
    }
    else if (mousecode == 5 || mousecode == 2)
    {
        data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom / 1.3));
        data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom / 1.3));
        data_mouse->zoom /= 1.3;
        data_mouse->nb_iter--;
    }
    fractol(data_mouse);
    printf("mousecode : %d\n", mousecode);
    return (0);
}
