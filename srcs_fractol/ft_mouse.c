/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 13:19:33 by vasalome    ###    #+. /#+    ###.fr     */
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

int     get_key_mouse(int m_code, int x, int y, t_fractol *data)
{
    printf("m_code 1 : %d\n", m_code);
    static t_fractol    *data_mouse = NULL;
    if (data_mouse == NULL)
        data_mouse = data;
    if ((m_code == 4 || m_code == 1) && x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_LENGHT)
    {
        data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom * 1.3));
        data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom * 1.3));
        data_mouse->zoom *= 1.3;
        data_mouse->nb_iter *= 1.3;
        data_mouse->zoom_info++;
    }
    else if (m_code == 5 || m_code == 2)
    {
        if(data_mouse->zoom_info > 0)
        {
            data_mouse->x1 = (x / data_mouse->zoom + data_mouse->x1) - (x / (data_mouse->zoom / 1.3));
            data_mouse->y1 = (y / data_mouse->zoom + data_mouse->y1) - (y / (data_mouse->zoom / 1.3));
            data_mouse->zoom /= 1.3;
            data_mouse->nb_iter /= 1.3;
            data_mouse->zoom_info--;
        }
    }
    printf("m_code 2 : %d\n", m_code);
    fractol(data_mouse);
    return (0);
}

int				mouse_hook(int button, int x, int y, t_fractol *data)
{
	get_key_mouse(button, x, y, data);
	fractol(data);
	return (0);
}