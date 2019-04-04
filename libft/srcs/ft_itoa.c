/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:52:31 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:08:24 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		count_digit(int n, int sign)
{
	long	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (n < 10)
	{
		i++;
	}
	if (sign == -1)
		return (i + 1);
	return (i);
}

char			*ft_itoa(int n)
{
	char	*result;
	char	*save;
	int		sign;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && (n = -n))
		sign = -1;
	if ((result = ft_strnew(count_digit(n, sign))) == NULL)
		return (NULL);
	save = result;
	while (n > 0)
	{
		*result++ = ((n % 10) + '0');
		n /= 10;
	}
	if (sign)
		*result++ = '-';
	*result = '\0';
	result = ft_strrev(save);
	return (result);
}
