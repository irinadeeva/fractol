/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:22 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 16:15:48 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default(t_fractol *data)
{
	data->min = init_complex(-2, -2);
	data->max.re = 2;
	data->max.im = data->min.im +
			(data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
	data->zoom = 1;
	data->max_iteration = 50;
	data->k = init_complex(0.0, 0.0);
	data->type_color = (data->type_fractal != 9) ? 1 : 4;
}

void	shift(int keycode, t_fractol *data)
{
	if (keycode == ARROW_UP)
	{
		data->min.im -= 0.1;
		data->max.im -= 0.1;
	}
	if (keycode == ARROW_DOWN)
	{
		data->min.im += 0.1;
		data->max.im += 0.1;
	}
	if (keycode == ARROW_LEFT)
	{
		data->min.re += 0.1;
		data->max.re += 0.1;
	}
	if (keycode == ARROW_RIGHT)
	{
		data->min.re -= 0.1;
		data->max.re -= 0.1;
	}
}

void	color_fratal(int keycode, t_fractol *data)
{
	if (keycode == BOARD_C)
	{
		if (data->type_fractal != 9)
			data->type_color == 9 ? data->type_color = 0 : 0;
		else
			data->type_color == 9 ? data->type_color = 3 : 0;
		data->type_color += 1;
	}
	if (keycode == BOARD_V)
	{
		if (data->type_color > 0 && data->type_color < 4)
			data->type_fractal == 8 ? data->type_fractal = 0 : 0;
		else
			data->type_fractal == 9 ? data->type_fractal = 0 : 0;
		data->type_fractal += 1;
	}
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == BOARD_ESC)
		exit(1);
	if (keycode == BROAD_SPACE)
		set_default(data);
	if ((keycode == PAD_PLUS || keycode == BOARD_PLUS)
	&& data->max_iteration < 150)
		data->max_iteration += 10;
	if ((keycode == PAD_MINUS || keycode == BOARD_MINUS)
	&& data->max_iteration > 10)
		data->max_iteration -= 10;
	if (keycode > 122 && keycode < 127)
		shift(keycode, data);
	if (keycode == BOARD_V || keycode == BOARD_C)
		color_fratal(keycode, data);
	get_threads(data);
	return (0);
}

int		exit_press(void)
{
	exit(1);
	return (0);
}
