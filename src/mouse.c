/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:29 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 16:06:15 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_motion(int x, int y, t_fractol *data)
{
	data->k = init_complex(
			4 * ((double)x / SIZE_WIN - 0.5),
			4 * ((double)(SIZE_WIN - y) / SIZE_WIN - 0.5));
	get_threads(data);
	return (0);
}

/*
**  factor - ratio between (x, y) and (re, im)
**  c - a point on display (where my mouse)
**  recount of (re, im) besed on zoom and shift
*/

int	mouse_press(int button, int x, int y, t_fractol *data)
{
	t_complex	factor;
	t_complex	c;
	double		zoom;

	factor = init_complex(
			(data->max.re - data->min.re) / (SIZE_WIN - 1),
			(data->max.im - data->min.im) / (SIZE_WIN - 1));
	c.im = data->max.im - y * factor.im;
	c.re = data->min.re + x * factor.re;
	if (button == 1 || button == 4)
		zoom = 0.9f;
	if (button == 2 || button == 5)
		zoom = 1.1f;
	data->zoom *= zoom;
	if (data->zoom >= 2)
		return (0);
	data->min.re = (data->min.re - c.re) * (zoom) + c.re;
	data->min.im = (data->min.im - c.im) * (zoom) + c.im;
	data->max.re = (data->max.re - c.re) * (zoom) + c.re;
	data->max.im = data->min.im +
			(data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
	get_threads(data);
	return (0);
}
