/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:13:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:44:22 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	int		i;
	int		len;
	char	*duplic;

	i = 0;
	len = (ft_strlen(src) < n) ? ft_strlen(src) : n;
	if (!(duplic = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	ft_strncpy(duplic, src, len);
	duplic[len] = '\0';
	return (duplic);
}
