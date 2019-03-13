/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 14:14:48 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 13:59:41 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

int		ft_usage(void)
{
    write(1, "\n", 1);
	write(1, "How to use ?              \n", 27);
    write(1, "\n", 1);
    write(1, "Exemple : ./fractol 4     \n", 27);
    write(1, ". 1 : Mandelbrot          \n", 27);
    write(1, ". 2 : Julia               \n", 27);
    write(1, ". 3 : Burningship         \n", 27);
    write(1, ". 4 : Tapis Sierpinski    \n", 27);
    write(1, ". 5 : Fractale needname   \n", 27);
    write(1, ". 6 : Fractale Portail    \n", 27);
    write(1, ". 7 : Fractale Tornado    \n", 27);
    write(1, ". 8 : Fractale needname   \n", 27);
    write(1, ". 9 : Fractale Nenufar    \n", 27);
    write(1, "\n", 1);
	return (64);
}

void	ft_whats_my_buttons(void)
{
    write(1, "\n", 1);
	write(1, "Notice ->                 \n", 27);
    write(1, "\n", 1);
    write(1, "Colors :                  \n", 27);
    write(1, ". C : Base orange         \n", 27);
    write(1, ". V : Base verte          \n", 27);
    write(1, ". B : Base bleue          \n", 27);
    write(1, ". N : Surprise            \n", 27);
    write(1, "\n", 1);
    write(1, "Options Zoom :            \n", 27);
    write(1, ". Z - Souris 1 : Zoom In  \n", 27);
    write(1, ". X - Souris 2 : Zoom Out \n", 27);
    write(1, ". Or use mouse wheel      \n", 27);
    write(1, "\n", 1);
    write(1, "Mouvements :              \n", 27);
    write(1, "Use Arrows                \n", 27);
    write(1, "\n", 1);
    write(1, "Autres     :              \n", 27);
    write(1, ". R : Reset               \n", 27);
    write(1, ". 1-9 : Change ur fractal \n", 27);
    write(1, "\n", 1);
}

int     red_cross()
{
    exit(0);
    return (0);
}
