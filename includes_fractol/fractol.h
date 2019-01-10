/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:49:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 13:22:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx_macos/mlx.h"
//#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_RESET 29
# define KEY_ESC 53
# define KEY_ITE_PLUS 22
# define KEY_ITE_MOINS 23

# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4

typedef struct  s_fractol
{
    float       nb_iter;
    void        *mlx;
    void        *win;
    intmax_t    x;
    intmax_t    y;
    intmax_t    zoom;
    int         w_width;
    int         w_lenght;
}               t_fractol;

typedef struct  s_coord
{
    double      x1;
    double      x2;
    double      y1;
    double      y2;
    double      c_r;
    double      c_i;
    double      z_r;
    double      z_i;
    double      tmp;
}               t_coord;

void    zoom_in(t_fractol *data);
void    zoom_out(t_fractol *data);
void    key_move(int key, t_fractol *move);
void	key_reset(t_fractol *reset);
int     get_key(int key, t_fractol *data);

void    ft_fractol(void *mlx_ptr, void *win_ptr, float iteration);

#endif