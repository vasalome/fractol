#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct  s_thread
{
    pthread_t   fred[THREADS];
    int         args[THHREADS];
}               t_thread;



void		*render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)m;
	y = WIN_HEIGHT / THREADS * t->id;
	while (y < WIN_HEIGHT / THREADS * (t->id + 1))
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			*(t->mlx->data + y * WIN_WIDTH + x) =
				t->mlx->fractal->pixel(x, y, &t->mlx->viewport, t->mlx);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &mlx->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(r->threads + i, NULL, render_thread, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	draw(mlx);
}

void		draw(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_LENGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			image_set_pixel(mlx->image, x, y, get_color(*(mlx->data + y * WIN_WIDTH + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}















void   fonction_fred(

ft_fred_n(data->x1, data->x2, data->y1, data->y2);

ft_winfred_1(0, 300, 0, 300);
ft_winfred_2(0, 300, 301, 600);
ft_winfred_3(0, 300, 601, 900);
ft_winfred_4(300, 600, 0, 300);
ft_winfred_5(300, 600, 301, 600);
ft_winfred_6(300, 600, 601, 900);
ft_winfred_7(600, 900, 0, 300);
ft_winfred_8(600, 900, 301, 600);
ft_winfred_9(600, 900, 601, 900);

int     fredo()
pthread_t   fred;

i = 0;
while (i <= 9)
{
    pthread_create(&fred, NULL, ft_winfred_1(0, 300, 0, 300), NULL);
    pthread_create(&fred, NULL, ft_winfred_2(0, 300, 301, 600), NULL);
    pthread_create(&fred, NULL, ft_winfred_3(0, 300, 601, 900), NULL);
    pthread_create(&fred, NULL, ft_winfred_4(300, 600, 0, 300), NULL);
    pthread_create(&fred, NULL, ft_winfred_5(300, 600, 301, 600), NULL);
    pthread_create(&fred, NULL, ft_winfred_6(300, 600, 601, 900) , NULL);
    pthread_create(&fred, NULL, ft_winfred_7(600, 900, 0, 300) , NULL);
    pthread_create(&fred, NULL, ft_winfred_8(600, 900, 301, 600), NULL);
    pthread_create(&fred, NULL, ft_winfred_9(600, 900, 601, 900), NULL);
    i++;
}

pthread_join(fred, NULL);



