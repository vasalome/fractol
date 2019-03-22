/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:14:09 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:26:10 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	while (n-- > 0)
		*str1++ = *str2++;
	return (dest);
}
