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

# define ZOOM_IN 5
# define ZOOM_OUT 4
# define KEY_UP
# define KEY_DOWN
# define KEY_LEFT
# define KEY_RIGHT

typedef struct  s_fractol
{
    float       nb_iter;
    void        *mlx;
    void        *win;
    float       x1;
    float       x2;
    float       y1;
    float       y2;
}               t_fractol;

/*
typedef struct  s_coord
{
    float       x1;
    float       x2;
    float       y1;
    float       y2;
}               t_coord;
*/



#endif