/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:49:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 16:44:24 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <Tk/X11/X.h>
# include <pthread.h>
# include <string.h>

# define WIDTH 700.0
# define HEIGHT 700.0

typedef struct		s_infos
{
	char			*s1;
	char			*s2;
	char			*s3;
	char			*s4;
}					t_infos;

typedef struct		s_fractol
{
	char			*name;
	double			nb_iter;
	void			*mlx;
	void			*win;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			x;
	double			y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			cmouse_r;
	double			cmouse_i;
	double			tmp;
	double			nzoom;
	double			zoom_info;
	double			image_x;
	double			image_y;
	int				color;
	int				color_in;
	int				stop_move;
	void			*img_ptr;
	unsigned int	*img_str;
	int				bpp;
	int				sl;
	int				end;
	int				hide;
}					t_fractol;

int					ft_usage(void);
void				ft_whats_my_buttons(void);
void				init_fract(t_fractol *data);
int					color_rgb_get_key(int i, t_fractol *data, double z_i);
void				fractol(t_fractol *data);
int					red_cross();
void				quit_me(t_fractol *data);

void				ft_mandelbrot(t_fractol *data, double x, double y);
void				ft_julia(t_fractol *data, double x, double y);
void				ft_douadyrabbit(t_fractol *data, double x, double y);
void				ft_deepturn(t_fractol *data, double x, double y);
void				ft_burningship(t_fractol *data, double x, double y);
void				ft_portail(t_fractol *data, double x, double y);
void				ft_tornado(t_fractol *data, double x, double y);
void				ft_virtualforest(t_fractol *data, double x, double y);
void				ft_nenufar(t_fractol *data, double x, double y);
void				ft_needname(t_fractol *data, double x, double y);
void				ft_choice(t_fractol *data, double x, double y);

int					get_key(int keycode, t_fractol *data);
int					get_my_mouse(int x, int y, t_fractol *data);
int					get_key_mouse(int m_code, int x, int y, t_fractol *data);
int					mouse_hook(int button, int x, int y, t_fractol *data);

void				put_pixel(t_fractol *data, int x, int y, int color);
void				infos(t_fractol *data);

#endif
