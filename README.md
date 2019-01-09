http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
http://www.relativitybook.com/CoolStuff/julia_set.html


gcc -I ./minilibx_macos/mlx.h srcs_fractol/main_fractol.c ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

ligne de couleur chelou qui bouge wesh
mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * z_i * 256 * 256 * 256 / iteration_max));
mlx_pixel_put(mlx_ptr, win_ptr, x, y, (i * z_r * 256 * 256 * 256 / iteration_max));


Keycode :
key w : 13
key a : 0
key s : 1
key d : 2

key haut : 126
key bas : 125
key gauche : 123
key droite : 124

key e : 14
key q : 12

key + : 69
key - : 78

key esc : 53

key 0 : 29
key 5 : 23
key 6 : 22

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