/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:44:44 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:50:17 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (s != '\0' && f != '\0')
	{
		i = 0;
		if (!(dest = ft_strdup(s)))
			return (NULL);
		while (dest[i])
		{
			dest[i] = f(dest[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
