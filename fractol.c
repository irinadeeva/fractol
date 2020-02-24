//
// Created by Brandy Hugo on 24/02/2020.
//
#include "fractol.h"

/*
** data_init  заполнение струкутуры входными данными
** mlx_init() создает соединение с графической системой
** mlx_new_window() открывает окно
** mlx_get_data_addr() считывание данных о системе
** mlx_hook() считывание событий с клавиутуры и мыши
** mlx_loop() не дает закрыться окну
*/

void	error_out(void)
{
    ft_putendl("Error!");
    exit(1);
}

int		key_hook(int keycode, t_fractol *data)
{
    if (keycode == BOARD_ESC)
        exit(1);
    return (0);
}

int		main(int argc, char **argv)
{
    int		size_line;
    int		end;
    t_fractol	*data;

    //if (argc != 2)
    //    error_out();
    if (!(data = (t_fractol *)malloc(sizeof(*data))))
        error_out();
    //data_init(data, argv);
    if ((data->mlx_ptr = mlx_init()) == NULL)
        error_out();
    data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE_WIN, SIZE_WIN, "FRACTOL");
    data->img_ptr = mlx_new_image(data->mlx_ptr, SIZE_WIN, SIZE_WIN);
    data->image_pix = (int *)
            mlx_get_data_addr(data->img_ptr, &data->bpp, &size_line, &end);
    mlx_hook(data->win_ptr, 2, 0, key_hook, data);
    mlx_loop(data->mlx_ptr);
    return (0);
}
