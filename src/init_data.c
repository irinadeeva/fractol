/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:37:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:40:24 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** init_data  заполнение струкутуры входными данными
** mlx_init() создает соединение с графической системой
** mlx_new_window() открывает окно
** mlx_get_data_addr() считывание данных о системе
** mlx_hook() считывание событий с клавиутуры и мыши
** mlx_loop() не дает закрыться окну
*/

void		init_window(t_fractol *data)
{
	int		end;

	if (!(data->mlx_ptr = mlx_init()))
		error_out();
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
					SIZE_WIN, SIZE_WIN, "FRACTOL")))
		error_out();
	if (!(data->img_ptr = mlx_new_image(data->mlx_ptr,
					SIZE_WIN, SIZE_WIN)))
		error_out();
	if (!(data->image_pix = mlx_get_data_addr(data->img_ptr,
					&data->bpp, &data->size_line, &end)))
		error_out();
}

/*
** max_iteration = 50; Чем больше будет указанное число, тем точнее будет
** полученное изображение фрактала.
** И тем больше вычислительных задач ляжет на компьютер.
*/

t_fractol	*init_data(int type_fractal)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(*data))))
		error_out();
	data->min = init_complex(-2, -2);
	data->max.re = 2;
	data->max.im = data->min.im + (data->max.re - data->min.re)
		* SIZE_WIN / SIZE_WIN;
	data->zoom = 1;
	data->type_fractal = type_fractal;
	data->max_iteration = 50;
	data->k = init_complex(0.0, 0.0);
	data->type_color = (data->type_fractal != 9) ? 1 : 4;
	return (data);
}
