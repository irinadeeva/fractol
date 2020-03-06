/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:01:58 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:09:49 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** So how to generate such a beautiful fractal?
** for every pixel, iterate znew = zold² + c on the
** complex plane until it leaves the circle around the origin with radius 2.
** The number of iterations it the color of the pixel.
*/

int	mandelbrot_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re + k.re,
				2.0 * z.re * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	julia_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + k.re,
				2.0 * z.re * z.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	burning_ship_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				&& iteration < max_iteration)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + c.re + k.re,
				-2.0 * fabs(z.re * z.im) + c.im + k.im);
		iteration++;
	}
	return (iteration);
}

int	mandelbar_function(t_complex c, int max_iteration, t_complex k)
{
	int			iteration;
	t_complex	z;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
			&& iteration < max_iteration)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + c.re + k.re,
				-2.0 * z.re * z.im + c.im + k.im);
		iteration++;
	}
	return (iteration);
}
