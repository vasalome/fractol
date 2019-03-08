/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 17:32:01 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:48:34 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ft_strlwr(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = ft_toupper(str[0]);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] <= 47)
			{
				str[i] = ft_toupper(str[i]);
			}
		}
		i++;
	}
	return (str);
}
