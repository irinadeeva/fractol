/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernstein_polynomials.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:40:33 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 15:40:36 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_color	get_color2(int iteration, int max_iteration)
{
	t_color	color;
	double	t;

	t = (double)iteration / max_iteration;
	color.channel[0] = 0;
	color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[3] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[2] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

t_color	get_color3(int iteration, int max_iteration)
{
	t_color	color;
	double	t;

	t = (double)iteration / max_iteration;
	color.channel[0] = 0;
	color.channel[3] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[1] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

t_color	get_color4(int iteration, int max_iteration)
{
	t_color	color;
	double	t;

	t = (double)iteration / max_iteration;
	color.channel[0] = 0;
	color.channel[2] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[1] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
