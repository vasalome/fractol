/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_plus.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 22:37:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 23:26:13 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

char	*ft_dtoa(double n, int precision)
{
	char	*s;
	long	tmp;
	long	t;
	int		length;

	if (!precision)
		return (ft_itoa((int)n));
	tmp = (n * pow(10, precision));
	t = (tmp < 0) ? -tmp : tmp;
	length = (n <= 0 ? 3 : 2);
	while (tmp && ++length)
		tmp /= 10;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[--length] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (t)
	{
		s[--length] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	return (s);
}

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
	double		zoomy;

	zoomy = ((WIDTH / 2) * data->nzoom / WIDTH + data->x1) - \
						(6 * data->zoom_info);
	string.s1 = ft_dtoa(data->c_r, 5);
	string.s2 = ft_dtoa(data->c_i, 5);
	string.s3 = ft_dtoa(data->nb_iter, 0);
	string.s4 = ft_dtoa(zoomy, 2);
	if (data->hide % 2 == 1)
		infos_string(data, &string);
	free(string.s1);
	free(string.s2);
	free(string.s3);
	free(string.s4);
}
