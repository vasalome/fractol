/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countsetbits.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:06:12 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 14:06:29 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_countsetbits(unsigned short n)
{
	int count;

	count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return (count);
}
