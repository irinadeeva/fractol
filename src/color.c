/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:05 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 15:56:25 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	red_color(int iteration, int max_iteration)
{
	t_color	color;

	if (iteration == max_iteration)
		ft_bzero(color.channel, 4);
	else
	{
		color.channel[0] = 0;
		color.channel[1] = 127;
		color.channel[2] = 0;
		color.channel[3] = 0;
	}
	return (color);
}

t_color	green_color(int iteration, int max_iteration)
{
	t_color	color;

	if (iteration == max_iteration)
		ft_bzero(color.channel, 4);
	else
	{
		ft_bzero(color.channel, 2);
		color.channel[2] = 127;
		color.channel[3] = 0;
	}
	return (color);
}

t_color	blue_color(int iteration, int max_iteration)
{
	t_color	color;

	if (iteration == max_iteration)
		ft_bzero(color.channel, 4);
	else
	{
		ft_bzero(color.channel, 3);
		color.channel[3] = 127;
	}
	return (color);
}

t_color	choose_color(int i, int max_iteration, int type_color, t_complex c)
{
	t_color	color;

	ft_bzero(color.channel, 4);
	if (type_color == 1)
		return (red_color(i, max_iteration));
	if (type_color == 2)
		return (blue_color(i, max_iteration));
	if (type_color == 3)
		return (green_color(i, max_iteration));
	if (type_color == 4)
		return (get_color(i, max_iteration));
	if (type_color == 5)
		return (get_color2(i, max_iteration));
	if (type_color == 6)
		return (get_color3(i, max_iteration));
	if (type_color == 7)
		return (get_color4(i, max_iteration));
	if (type_color == 8)
		return (continuous_colouring(i, c));
	if (type_color == 9)
		return (continuous_colouring2(i, c));
	else
		return (color);
}
