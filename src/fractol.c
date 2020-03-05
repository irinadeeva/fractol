//
// Created by Brandy Hugo on 24/02/2020.
//
#include "fractol.h"

void	error_out(void)
{
    ft_putendl("Error!");
    exit(1);
}

/*
** init_data  заполнение струкутуры входными данными
** mlx_init() создает соединение с графической системой
** mlx_new_window() открывает окно
** mlx_get_data_addr() считывание данных о системе
** mlx_hook() считывание событий с клавиутуры и мыши
** mlx_loop() не дает закрыться окну
*/


void    start_hooks(t_fractol *data)
{
    mlx_hook(data->win_ptr, 2, 0, key_hook, data);
    mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
   // mlx_hook(data->win_ptr, 5, 0, mouse_release_hook, data);
    mlx_hook(data->win_ptr, 6, 0, julia_motion, data);
    mlx_hook(data->win_ptr, 17, 1L << 17, exit_press, NULL);
    mlx_loop(data->mlx_ptr);
}

void init_window(t_fractol	*data)
{
    int		end;

    if (!(data->mlx_ptr = mlx_init()))
        error_out();
    if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE_WIN, SIZE_WIN, "FRACTOL")))
        error_out();
    if (!(data->img_ptr = mlx_new_image(data->mlx_ptr, SIZE_WIN, SIZE_WIN)))
        error_out();
    if (!(data->image_pix = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &end)))
        error_out();

}

t_fractol  *init_data(int type_fractal)
{
    t_fractol	*data;

    if (!(data = (t_fractol *)malloc(sizeof(*data))))
        error_out();
    data->min = init_complex(-2, -2);
    data->max.re = 2;
    data->max.im = data->min.im + (data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
    data->zoom = 1;
    data->type_fractal = type_fractal;
    data->max_iteration = 40; // Чем больше будет указанное число, тем точнее будет полученное изображение фрактала. И тем больше вычислительных задач ляжет на компьютер.
    data->k = init_complex(-0.4, 0.6);
    return (data);
}

void    start_fractal(int type_fractal)
{
    t_fractol	*data;

    data = init_data(type_fractal);
    init_window(data);
    get_threads(data);
    start_hooks(data);
}

void    print_help()
{
    ft_putendl("A parameter is passed on the command line to define what type of fractal will be viewed.\n"
           "Please, choose one:\n"
           "      -1 the Mandelbrot set\n"
           "      -2 the Julia set\n"
           "      -3 the Burning Ship set \n"
           "      -4 the Mandelbar set\n"
           "      -5 the Celtic Mandelbrot set \n"
           "      -6 the Celtic Mandelbar set \n"
           "      -7 the Celtic Perpendicular set \n"
           "      -8 the Perpendicular Mandelbrot set\n"
           "\033[31mUsage: ./fractol <-number>\n");
}

void type_of_fractal(char *s)
{
    if (ft_strcmp(s, "-1") == 0)
        start_fractal(1);
    if (ft_strcmp(s, "-2") == 0)
        start_fractal(2);
    if (ft_strcmp(s, "-3") == 0)
        start_fractal(3);
    if (ft_strcmp(s, "-4") == 0)
        start_fractal(4);
    if (ft_strcmp(s, "-5") == 0)
        start_fractal(5);
    if (ft_strcmp(s, "-6") == 0)
        start_fractal(6);
    if (ft_strcmp(s, "-7") == 0)
        start_fractal(7);
    if (ft_strcmp(s, "-8") == 0)
        start_fractal(8);
    else
        print_help();
}

int		main(int argc, char **argv)
{
    if (argc == 2)
        type_of_fractal(argv[1]);
    else
        print_help();
    return (0);
}
