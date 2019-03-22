/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_colors.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 13:32:45 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 13:32:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int		color_rgb_get_key(int i, t_fractol *data, double z_i)
{
	int		r;
	int		g;
	int		b;

	r = (i * 16) % 256;
	g = (i * 8) % 256;
	b = (i * 4) % 256;
	if (data->color == 1)
		return (r * 65536 + g * 256 + b);
	if (data->color == 2)
		return (g * 65536 + r * 256 + b);
	if (data->color == 3)
		return (b * 65536 + g * 256 + r);
	if (data->color == 4)
		return (((((i * 16) * 65536) + z_i * 256 * 256 * i) * z_i));
	return (0);
}
