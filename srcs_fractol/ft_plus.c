/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_plus.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 22:37:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:37:31 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void		infos_string(t_fractol *data, t_infos *string)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xffffff, "c_r :");
	mlx_string_put(data->mlx, data->win, 65, 10, 0xffffff, \
		string->s1);
	mlx_string_put(data->mlx, data->win, 10, 30, 0xffffff, "c_i :");
	mlx_string_put(data->mlx, data->win, 65, 30, 0xffffff, \
		string->s2);
	mlx_string_put(data->mlx, data->win, 10, 60, 0xffffff, "ite :");
	mlx_string_put(data->mlx, data->win, 65, 60, 0xffffff, \
		string->s3);
	mlx_string_put(data->mlx, data->win, 10, 80, 0xffffff, "zoom:");
	mlx_string_put(data->mlx, data->win, 65, 80, 0xffffff, \
		string->s4);
	if (!(ft_strcmp(data->name, "2")))
		if (data->stop_move % 2 == 0)
			mlx_string_put(data->mlx, data->win, 10, (HEIGHT - 30), \
				0xffffff, "Pause");
}

void		infos(t_fractol *data)
{
	t_infos		string;

	string.s1 = ft_dtoa(data->c_r, 5);
	string.s2 = ft_dtoa(data->c_i, 5);
	string.s3 = ft_dtoa(data->nb_iter, 0);
	string.s4 = ft_dtoa(data->zoom_info * 100, 0);
	if (data->hide % 2 == 1)
		infos_string(data, &string);
	free(string.s1);
	free(string.s2);
	free(string.s3);
	free(string.s4);
}
