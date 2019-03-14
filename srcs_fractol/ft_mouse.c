/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 19:29:43 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
#include "../includes_fractol/keys.h"

int     get_my_mouse(int x, int y, t_fractol *data)
{
    static t_fractol *data_mouse = NULL;
    double  x1;
    double  x2;

    if (data_mouse == NULL)
        data_mouse = data;
    if (!(ft_strcmp(data_mouse->name, "2")))
    {
        x1 = x;
        x2 = y;
        data_mouse->cmouse_r = x1 / 660;
        data_mouse->cmouse_i = x2 / 660;
        fractol(data_mouse);
    }
    return (0);
}

int     get_key_mouse(int mousecode, int x, int y, t_fractol *data)
{
    static t_fractol    *data_mouse = NULL;
    if (data_mouse == NULL)//////
        data_mouse = data;//////
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
    return (0);
}
