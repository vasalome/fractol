/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keyboard.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:46:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 18:45:07 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void	zoom_in(t_fractol *data)
{
	data->zoom += data->zoom * 1.1;
	data->x += data->x * 1.1;
	data->y += data->y * 1.1;
}

void	zoom_out(t_fractol *data)
{
	if (data->zoom / 1.1 < 10)
		return ;
	data->zoom += data->zoom / 1.1;
	data->x += data->x / 1.1;
	data->y += data->y / 1.1;
}

void	key_reset(t_fractol *reset)
{
	reset->x = 0;
	reset->y = 0;
	reset->zoom = 150;
	reset->nb_iter = 100;
}

void	key_move(int key, t_fractol *move)
{
	if (key == KEY_UP)
		move->y += 100;
	else if (key == KEY_DOWN)
		move->y += 100;
	else if (key == KEY_LEFT)
		move->x += 100;
	else if (key == KEY_RIGHT)
		move->x += 100;
}

int		get_key(int key, t_fractol *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_ZOOM_IN)
		zoom_in(data);
	else if (key == KEY_ZOOM_OUT)
		zoom_out(data);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key ==  KEY_RIGHT)
		key_move(key, data);
	else if (key == KEY_ITE_PLUS)
		data->nb_iter += 1;
	else if (key == KEY_ITE_MOINS)
		data->nb_iter -= 1;
	else if (key == KEY_RESET)
		key_reset(data);
	ft_fractol(data->mlx, data->win, data->nb_iter);
	printf("key : %d\n", key);
	return (0);
}
