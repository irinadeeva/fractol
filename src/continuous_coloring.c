/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continuous_coloring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:29:51 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 15:37:25 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	continuous_colouring(int iteration, t_complex c)
{
	t_color	color;
	double	continuous_index;
	double	z;

	z = sqrt(c.re * c.re + c.im * c.im);
	continuous_index = iteration + 1 - (log(fabs(z))) / log(2);
	color.channel[0] = 0;
	color.channel[3] = (int8_t)(sin(0.017 * continuous_index + 4) * 230 + 25);
	color.channel[2] = (int8_t)(sin(0.013 * continuous_index + 2) * 230 + 25);
	color.channel[1] = (int8_t)(sin(0.02 * continuous_index + 1) * 230 + 25);
	return (color);
}

t_color	continuous_colouring2(int iteration, t_complex c)
{
	t_color	color;
	double	continuous_index;
	double	z;

	z = sqrt(c.re * c.re + c.im * c.im);
	continuous_index = iteration + 1 - (log(fabs(z))) / log(2);
	color.channel[0] = 0;
	color.channel[1] = (int8_t)(sin(0.017 * continuous_index + 4) * 230 + 25);
	color.channel[2] = (int8_t)(sin(0.013 * continuous_index + 2) * 230 + 25);
	color.channel[3] = (int8_t)(sin(0.02 * continuous_index + 1) * 230 + 25);
	return (color);
}
