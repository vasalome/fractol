/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 22:13:59 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:51:42 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tempo;

	j = 0;
	while (str[j] != '\0')
		j++;
	i = -1;
	while (++i < --j)
	{
		tempo = str[i];
		str[i] = str[j];
		str[j] = tempo;
	}
	return (str);
}
