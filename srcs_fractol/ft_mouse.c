/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:39:07 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int     mouse_move_hook(int x, int y, t_fractol *move)
{
    if (x < 0 || x >= move->w_width || y < 0 || y >= move->w_lenght)
        return (0);
    move->

}

int     mouse_click_hook()
{

}