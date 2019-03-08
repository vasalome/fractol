/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btree_insert_data.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 17:00:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:06:29 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		ft_btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		ft_btree_insert_data(&(*root)->left, item, cmpf);
	else
		ft_btree_insert_data(&(*root)->right, item, cmpf);
}
