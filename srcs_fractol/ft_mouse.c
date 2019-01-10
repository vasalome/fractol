/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 18:45:02 by vasalome    ###    #+. /#+    ###.fr     */
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

int     mouse_click_hook(int m_key, int x, int y, t_fractol *m_click)
{
    if (m_key == MOUSE_ZOOM_IN)
    {
        m_click->x += x / 5;
        m_click->y += y / 5;
        m_click->zoom = m_click->zoom * 1.2;
        m_click->x = m_click->x * 1.2;
        m_click->y = m_click->y * 1.2;
    }
    if (m_key == MOUSE_ZOOM_OUT)
    {
        m_click->x += x / 5;
        m_click->y += y / 5;
        m_click->zoom = m_click->zoom * 1.2;
        m_click->x = m_click->x * 1.2;
        m_click->y = m_click->y * 1.2;
    }
    m_click->ft_fractol(m_click)
    return (0);
}