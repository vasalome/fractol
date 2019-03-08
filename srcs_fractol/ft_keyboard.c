/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keyboard.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:46:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 18:13:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int     get_key(int keycode, t_fractol *data)
{
    static t_fractol    *data_key = NULL;
    printf("code erreur: get_key A - ENTRER\n");
    if (data_key == NULL)
        data_key = data;
    if (keycode == 53)
        exit(0);
    else if (keycode == 69)
        data_key->nb_iter += 20;
    else if (keycode == 78)
        data_key->nb_iter -= 20;
    else if (keycode == 126)
    {
        data_key->y1 += 0.1;
        data_key->y2 += 0.1;
    }
    else if (keycode == 125)
    {
        data_key->y1 -= 0.1;
        data_key->y2 -= 0.1;
    }
    else if (keycode == 123)
    {
        data_key->x1 += 0.1;
        data_key->x2 += 0.1;
    }
    else if (keycode == 124)
    {
        data_key->x1 -= 0.1;
        data_key->x2 -= 0.1;
    }
    else if (keycode == 8)
        data_key->color = 1;
    else if (keycode == 9)
        data_key->color = 2;
    else if (keycode == 11)
        data_key->color = 3;
    else if (keycode == 45)
        data_key->color = 4;
    else if (keycode == 15)
        init_fract(data_key);
    //else if (keycode == 4)
        //hide_info;
    else if (keycode == 6)
    {
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom * 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom * 1.3));
        data_key->zoom *= 1.3;
        data_key->nb_iter += 10;
    }
    else if (keycode == 7)
    { // Maybe : Ajouter un blocage pour empecher le zoom > 0 sinon segfault
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom / 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom / 1.3));
        data_key->zoom /= 1.3;
        data_key->nb_iter -= 10;
    }
    else if (keycode == 18)
        data_key->name = "1";
    else if (keycode == 19)
        data_key->name = "2";
    else if (keycode == 20)
        data_key->name = "3";
    else if (keycode == 21)
        data_key->name = "4";
    else if (keycode == 23)
        data_key->name = "5";
    else if (keycode == 22)
        data_key->name = "6";
    else if (keycode == 26)
        data_key->name = "7";
    else if (keycode == 28)
        data_key->name = "8";
    else if (keycode == 25)
        data_key->name = "9";
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("code erreur: get_key A - SORTIE\n");
    return (0);
}
