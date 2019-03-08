/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:51:03 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:52:06 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	sub = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (len--)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	return (sub);
}
