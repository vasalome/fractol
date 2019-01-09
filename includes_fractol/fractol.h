/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:49:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 18:10:10 by vasalome    ###    #+. /#+    ###.fr     */
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

# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4

typedef struct  s_fractol
{
    float       nb_iter;
    void        *mlx;
    void        *win;
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



#endif