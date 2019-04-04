/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 14:06:06 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:34:22 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_pow(int nb, int power)
{
	int		result;

	if (nb < 0)
		nb *= -1;
	if (power == 0)
		return (1);
	if ((power < 0) || (nb == 0))
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
