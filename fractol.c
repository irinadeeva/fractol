//
// Created by Brandy Hugo on 24/02/2020.
//
#include "fractol.h"

void	error_out(void)
{
    ft_putendl("Error!");
    exit(1);
}

t_complex init_complex(double re, double im)
{
    t_complex complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}

void	put_pixel(t_fractol *data, int x, int y, t_color color)
{
    int	i;

    i = (x * data->bpp / 8) + (y * data->size_line);
    if (i < SIZE_WIN * data->size_line)
    {
        data->image_pix[i] = color.channel[3];
        data->image_pix[++i] = color.channel[2];
        data->image_pix[++i] = color.channel[1];
        data->image_pix[++i] = color.channel[0];
    }

}

t_color	get_color(int iteration, int max_iteration)
{
    t_color	color;
    double	t;

    t = (double)iteration / max_iteration;
    color.channel[0] = 0;
    color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

// So how to generate such a beautiful fractal?
// for every pixel, iterate znew = zold² + c on the complex plane until it leaves the circle around the origin with radius 2.
// The number of iterations it the color of the pixel.

int mandelbrot_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    iteration = 0;
    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < max_iteration)
    {
        z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, 2.0 * z.re * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

/*
** data_init  заполнение струкутуры входными данными
** mlx_init() создает соединение с графической системой
** mlx_new_window() открывает окно
** mlx_get_data_addr() считывание данных о системе
** mlx_hook() считывание событий с клавиутуры и мыши
** mlx_loop() не дает закрыться окну
*/

int		main(int argc, char **argv)
{
    int		end;
    t_fractol	*data;

    //if (argc != 2)
    //    error_out();
    if (!(data = (t_fractol *)malloc(sizeof(*data))))
        error_out();
    //data = {0};
    data->min = init_complex(-2, -2);
    data->max.re = 2;
    data->max.im = data->min.im + (data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
    data->i = 0.1;
    data->zoom = 1;
    if (!(data->mouse = (t_mouse *)malloc(sizeof(*data->mouse))))
        error_out();
    data->mouse->button = 0;
    data->mouse->x = 0;
    data->mouse->y = 0;
    //data_init(data, argv);
    if ((data->mlx_ptr = mlx_init()) == NULL)
        error_out();
    data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE_WIN, SIZE_WIN, "FRACTOL"); // detect from NULL
    data->img_ptr = mlx_new_image(data->mlx_ptr, SIZE_WIN, SIZE_WIN); // detect from NULL
    data->image_pix = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &end);
    get_threads(data);
    mlx_hook(data->win_ptr, 2, 0, key_hook, data);
    mlx_hook(data->win_ptr, 5, 0, mouse_release_hook, data);
    //mlx_hook(data->win_ptr, 4, 0, mouse_press_hook, v);
    //mlx_hook(data->win_ptr, 6, 0, motion_hook, v);
    mlx_loop(data->mlx_ptr);
    return (0);
}
