/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:49:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 19:53:02 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <Tk/X11/X.h>

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_RESET 15
# define KEY_ESC 53
# define KEY_ITE_PLUS 22
# define KEY_ITE_MOINS 23

# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4

# define WIN_WIDTH 800
# define WIN_LENGHT 800

typedef struct      s_fractol
{
        char        *name;
        double      nb_iter;
        void        *mlx;
        void        *win;
        intmax_t    x1;
        intmax_t    x2;
        intmax_t    y1;
        intmax_t    y2;
        intmax_t    x;
        intmax_t    y;
        double      c_r;
        double      c_i;
        double      z_r;
        double      z_i;
        double      cmouse_r;
        double      cmouse_i;
        double      tmp;
        intmax_t    zoom;
        int         color;
}                   t_fractol;

int		ft_usage(void);
void	ft_whats_my_buttons(void);
void    init_fract(t_fractol *data);
int     color_rgb_get_key(int i, t_fractol *data, double z_i);
void    fractol(t_fractol *data);
int     red_cross();

void    ft_mandelbrot(t_fractol *data, double x, double y);
void    ft_julia(t_fractol *data, double x, double y);
void    ft_burningship(t_fractol *data, double x, double y);
void    ft_tapis(t_fractol *data, double x, double y);
void    ft_triangle(t_fractol *data, double x, double y);
void    ft_portail(t_fractol *data, double x, double y);
void    ft_tornado(t_fractol *data, double x, double y);
void    ft_perso3(t_fractol *data, double x, double y);
void    ft_nenufar(t_fractol *data, double x, double y);
void    ft_choice(t_fractol *data, double x, double y);

int     get_key(int keycode, t_fractol *data);
int     get_my_mouse(int x, int y, t_fractol *data);
int     get_key_mouse(int mousecode, int x, int y, t_fractol *data);

#endif