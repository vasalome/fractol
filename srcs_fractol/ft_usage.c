/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:14:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 13:55:25 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int		ft_usage(void)
{
	write(1, "How to use ?              \n", 27);
    write(1, "\n", 1);
    write(1, "Exemple : ./fractol 4     \n", 27);
    write(1, "1 : Mandelbrot            \n", 27);
    write(1, "2 : Julia                 \n", 27);
    write(1, "3 : Burningship           \n", 27);
    write(1, "4 : Tapis Sierpinski      \n", 27);
    write(1, "5 : Triangle Sierpinski   \n", 27); // ou fougere
    //
    write(1, "6 : Couleur A             \n", 27);
    write(1, "7 : Couleur B             \n", 27);
    write(1, "8 : Couleur C             \n", 27);
    write(1, "9 : Couleur in-imaginaire \n", 27);
	return (64);
}