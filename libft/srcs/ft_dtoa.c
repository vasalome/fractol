/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 14:18:36 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:40:04 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned int	dtoa_len(double nb, unsigned int precision)
{
	unsigned int	len;
	double			x;

	len = 1;
	x = nb;
	if (x < 1.0)
		len++;
	while (x >= 1)
	{
		len++;
		x /= 10.0;
	}
	return (len + precision + 1);
}

static void			dtoa_dot(char *buff, double nb, \
	unsigned int precision, const char *map)
{
	long	x;

	if (!precision)
		return ;
	*(buff++) = '.';
	nb -= (double)((__int128)nb);
	x = (long)(nb * ft_pow(10, (int)precision));
	while (precision--)
	{
		buff[precision] = map[x % 10];
		x /= 10;
	}
}

char				*ft_dtoa(double nb, unsigned int precision)
{
	char			*buff;
	const char		signe = (nb < 0.0 || *((long *)&nb) < 0) ? 1 : 0;
	unsigned int	len;
	const char		*map = "0123456789";

	if (signe)
		nb = -nb;
	len = dtoa_len(nb, precision) + (unsigned int)signe - \
		((!precision) ? 1 : 0);
	if (!(buff = malloc(sizeof(char) * len)))
		return (NULL);
	buff[--len] = '\0';
	if (precision)
		len -= precision + 1;
	dtoa_dot(buff + len, nb, precision, map);
	if (nb < 1.0)
		buff[--len] = '0';
	while (nb >= 1.0)
	{
		buff[--len] = map[(unsigned int)nb % 10];
		nb /= 10.0;
	}
	if (signe)
		buff[0] = '-';
	return (buff);
}
