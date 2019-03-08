/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_last.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 18:25:39 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 18:48:08 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_last(t_list **alst, t_list *elem)
{
	t_list		*tempo;
	t_list		*last;

	tempo = *alst;
	if (*alst == NULL)
		*alst = elem;
	else
	{
		while (tempo)
		{
			last = tempo;
			tempo = tempo->next;
		}
		last->next = elem;
	}
}
