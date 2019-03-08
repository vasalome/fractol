/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:05:40 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 14:06:05 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	size_t	i;
	char	ptr;

	i = 0;
	while (*s && (ptr = ft_strchr(charset, *s++) == NULL))
		i++;
	return (i);
}
