/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:11 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:32:57 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		put_pixel(t_fractol *data, int x, int y, t_color color)
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

int			choose_fractal(t_complex c, t_fractol *data)
{
	if (data->type_fractal == 1)
		return (mandelbrot_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 2)
		return (julia_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 3)
		return (burning_ship_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 4)
		return (mandelbar_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 5)
		return (celtic_mandelbrot_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 6)
		return (celtic_mandelbar_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 7)
		return (celtic_perpendicular_function(c, data->max_iteration, data->k));
	if (data->type_fractal == 8)
		return (perpendicular_mandelbrot(c, data->max_iteration, data->k));
	if (data->type_fractal == 9)
		return (newton_function(c, data->max_iteration));
	else
		return (0);
}

/*
** int y - y coordinate will be the imaginary part.
** int x - x coordinate will represent the real part of its complex coordinates
** t_complex min; borders of the image
** t_complex max; borders of the image
** t_complex factor; ratio complex to (x;y)
** связь между комплексными числами и пикселями на экране
** t_complex c; for each pixel apply an iterated complex function,
** the pixel  at the lower right corner
** of the image has coordinates [ImageWidth-1, ImageHeight-1]
** c.im = max.im - y * factor.im; считается особым образом.
** Это происходит по причине того, что
** ось y в окне программы направлена сверху вниз,
** а не снизу вверх как мы привыкли.
*/

void		draw_fractol(t_fractol *data)
{
	t_pixel		a;
	int			iteration;
	t_complex	factor;
	t_complex	c;
	t_color		color;

	factor = init_complex(((data->max.re - data->min.re)) / (SIZE_WIN - 1),
			((data->max.im - data->min.im)) / (SIZE_WIN - 1));
	a.y = data->start;
	while (a.y < data->finish)
	{
		c.im = data->max.im - a.y * factor.im;
		a.x = 0;
		while (a.x < (SIZE_WIN * data->bpp / 8))
		{
			c.re = data->min.re + a.x * factor.re;
			iteration = choose_fractal(c, data);
			color = choose_color(iteration, data->max_iteration,
					data->type_color, c);
			put_pixel(data, a.x, a.y, color);
			a.x++;
		}
		a.y++;
	}
}

void		get_threads(t_fractol *data)
{
	pthread_t	threads[NUM_THREADS];
	t_fractol	data2[NUM_THREADS];
	int			i;
	int			k;

	i = 0;
	k = (SIZE_WIN * data->bpp / 8) / NUM_THREADS;
	while (i < NUM_THREADS)
	{
		data2[i] = *data;
		data2[i].start = i * k;
		data2[i].finish = (i + 1) * k;
		if (pthread_create(&threads[i], NULL,
				(void *(*)(void *))draw_fractol, (void *)&data2[i]))
			error_out();
		i++;
	}
	while (i-- > 0)
	{
		if (pthread_join(threads[i], NULL))
			error_out();
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (SIZE_WIN == 1000)
		menu(data);
}
