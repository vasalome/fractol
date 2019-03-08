/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:45:12 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:50:24 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (s != '\0' && f != '\0')
	{
		if (!(dest = ft_strdup(s)))
			return (NULL);
		i = 0;
		while (dest[i])
		{
			dest[i] = f(i, dest[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
