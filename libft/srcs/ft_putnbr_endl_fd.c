/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_endl_fd.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 18:37:28 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 18:38:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_endl_fd(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	ft_putchar_fd(n, fd);
}
