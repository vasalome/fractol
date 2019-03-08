/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:06:09 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:51:14 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		len_max;

	len_max = len;
	if (len > ft_strlen(s2))
		len_max = ft_strlen(s2);
	i = 0;
	while (i < len && s1[i])
	{
		if (ft_strncmp(s1 + i, s2, len_max) == 0)
		{
			if (i + ft_strlen(s2) > len)
				return (NULL);
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
