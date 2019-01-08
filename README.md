http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
http://www.relativitybook.com/CoolStuff/julia_set.html


gcc -I ./minilibx_macos/mlx.h srcs_fractol/main_fractol.c ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

ligne de couleur chelou qui bouge wesh
mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * z_i * 256 * 256 * 256 / iteration_max));
mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * z_r * 256 * 256 * 256 / iteration_max));


Keycode :
w : 13
a : 0
s : 1
d : 2

haut : 126
bas : 125
gauche : 123
droite : 124

e : 14
q : 12

+ : 69
- : 78

esc : 53

Mandelbrot
c_r = x / zoom + x1;
c_i = y / zoom + y1;
z_r = 0;
z_i = 0;

Quaternion Julia
c_r = -0.75;
c_i = -0.14;
z_r = x / zoom + x1;
z_i = y / zoom + y1;

Ensemble de Julia
c_r = 0.285;
c_i = 0.01;
z_r = x / zoom + x1;
z_i = y / zoom + y1;