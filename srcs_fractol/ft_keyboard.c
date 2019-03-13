/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keyboard.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:46:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 18:49:30 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
#include "../includes_fractol/keys.h"

int     get_key(int keycode, t_fractol *data)
{
    static t_fractol    *data_key = NULL;
    printf("code erreur: get_key A - ENTRER\n");
    if (data_key == NULL)
        data_key = data;
    if (keycode == KEY_ESC)
        exit(0);
    else if (keycode == KEY_ITE_MORE)
        data_key->nb_iter += 20;
    else if (keycode == KEY_ITE_LESS)
        data_key->nb_iter -= 20;
    else if (keycode == KEY_UP)
    {
        data_key->y1 += 0.001 * data_key->zoom;
        data_key->y2 += 0.001 * data_key->zoom;
    }
    else if (keycode == KEY_DOWN)
    {
        data_key->y1 -= 0.001 * data_key->zoom;
        data_key->y2 -= 0.001 * data_key->zoom;
    }
    else if (keycode == KEY_LEFT)
    {
        data_key->x1 += 0.001 * data_key->zoom;
        data_key->x2 += 0.001 * data_key->zoom;
    }
    else if (keycode == KEY_RIGHT)
    {
        data_key->x1 -= 0.001 * data_key->zoom;
        data_key->x2 -= 0.001 * data_key->zoom;
    }
    else if (keycode == KEY_C)
        data_key->color = 1;
    else if (keycode == KEY_V)
        data_key->color = 2;
    else if (keycode == KEY_B)
        data_key->color = 3;
    else if (keycode == KEY_N)
        data_key->color = 4;
    else if (keycode == KEY_RESET)
        init_fract(data_key);
    else if (keycode == KEY_ZOOM_IN)
    {
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom * 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom * 1.3));
        data_key->zoom *= 1.3;
        data_key->nb_iter += 10;
    }
    else if (keycode == KEY_ZOOM_OUT)
    { // Maybe : Ajouter un blocage pour empecher le zoom > 0 sinon segfault
        data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom / 1.3));
        data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom / 1.3));
        data_key->zoom /= 1.3;
        data_key->nb_iter -= 10;
    }
    else if (keycode == KEY_1)
        data_key->name = "1";
    else if (keycode == KEY_2)
        data_key->name = "2";
    else if (keycode == KEY_3)
        data_key->name = "3";
    else if (keycode == KEY_4)
        data_key->name = "4";
    else if (keycode == KEY_5)
        data_key->name = "5";
    else if (keycode == KEY_6)
        data_key->name = "6";
    else if (keycode == KEY_7)
        data_key->name = "7";
    else if (keycode == KEY_8)
        data_key->name = "8";
    else if (keycode == KEY_9)
        data_key->name = "9";
    fractol(data_key);
    printf("keycode : %d\n", keycode);
    printf("code erreur: get_key A - SORTIE\n");
    return (0);
}
