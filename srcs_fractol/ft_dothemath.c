/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dothemath.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:43:19 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 18:58:15 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void	ft_fractol(void *mlx_ptr, void *win_ptr, float iteration)
{
	float	x1 = -2;
	float	x2 = 2;
	float	y1 = -2;
	float	y2 = 2;
	float	zoom = 150;
	int		iteration_max = iteration;

	float	image_x = (x2 - x1) * zoom;
	float	image_y = (y2 - y1) * zoom;

	float	c_r = 0;
	float	c_i = 0;
	float	z_r = 0;
	float	z_i = 0;
	float	i = 0;
	float	tmp = 0;

	float	x = 0;
	float	y = 0;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			ft_fractol_choose(fract_name); // faire le lien avec le bon fractol
			i = 0;
			while (((z_r * z_r + z_i * z_i)) < 4 && (i < iteration_max))
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * 256 * 256 * z_r / iteration_max));
			y++;
		}
		x++;
	}
}
