/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_colors.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 13:32:45 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 16:45:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int     color_rgb_orange(int i)
{
    int r;
    int g;
    int b;

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    return (r * 65536 + g * 256 + b);
}

int     color_rgb_vert(int i)
{
    int r;
    int g;
    int b;

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    return (g * 65536 + r * 256 + b);
}

int     color_rgb_violet(int i)
{
    int r;
    int g;
    int b;

    r = (i * 16) % 256;
    g = (i * 8) % 256;
    b = (i * 4) % 256;
    return (b * 65536 + r * 256 + g);
}

void    stupid_color(int i)
{
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * z_r * 256 * 256 * 256 / iteration_max));
}