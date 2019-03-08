/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:51:45 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:52:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char const		*end;

	if (s == NULL)
		return (NULL);
	while (*s == '\t' || *s == '\n' || *s == ' ')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	end = s + ft_strlen(s) - 1;
	while (*end == '\t' || *end == '\n' || *end == ' ')
		end--;
	return (ft_strsub(s, 0, end - s + 1));
}
