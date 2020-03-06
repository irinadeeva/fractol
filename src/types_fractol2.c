/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_fractol2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:04:20 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:04:21 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	celtic_mandelbrot_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max_iteration)
	{
		z = init_complex(
				fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re + k.re,
				2.0 * z.re * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	celtic_perpendicular_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max_iteration)
	{
		z = init_complex(
				fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re + k.re,
				-2.0 * fabs(z.re) * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	celtic_mandelbar_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max_iteration)
	{
		z = init_complex(
				fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re + k.re,
				-2.0 * z.re * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	perpendicular_mandelbrot(t_complex c, int max, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + c.re + k.re,
				-2.0 * fabs(z.re) * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	newton_function(t_complex c, int max_iteration)
{
	int			iteration;
	t_complex	z;
	t_complex	old;
	double		tmp;

	z = init_complex(c.re, c.im);
	iteration = 0;
	tmp = 1.0;
	while (tmp > 0.1 && iteration < max_iteration)
	{
		old.re = z.re;
		old.im = z.im;
		tmp = (z.re * z.re + z.im * z.im) * (z.re * z.re + z.im * z.im);
		z.re = (2 * z.re * tmp + z.re * z.re - z.im * z.im) / (3.0 * tmp);
		z.im = (2 * z.im * (tmp - old.re)) / (3.0 * tmp);
		tmp = (z.re - old.re) * (z.re - old.re) +
				(z.im - old.im) * (z.im - old.im);
		iteration++;
	}
	return (iteration);
}
