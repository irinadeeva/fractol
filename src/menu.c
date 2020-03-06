/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:29 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:36:53 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_fractol *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 0, WHITE, TEXT);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 30, WHITE, TEXT1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 60, WHITE, TEXT2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 90, WHITE, TEXT3);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 120, WHITE, TEXT4);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 150, WHITE, TEXT5);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 180, WHITE, TEXT9);
}

void	print_help(void)
{
	ft_putendl("A parameter is passed on the command line"
			"to define what type of fractal will be viewed.\n"
				"Please, choose one:\n"
				"      -1 the Mandelbrot set\n"
				"      -2 the Julia set\n"
				"      -3 the Burning Ship set \n"
				"      -4 the Mandelbar set\n"
				"      -5 the Celtic Mandelbrot set \n"
				"      -6 the Celtic Mandelbar set \n"
				"      -7 the Celtic Perpendicular set \n"
				"      -8 the Perpendicular Mandelbrot set\n"
				"      -9 the The Newton set\n"
				"\033[31mUsage: ./fractol <-number>\n");
}
