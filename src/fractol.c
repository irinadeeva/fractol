/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:19 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:42:07 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_out(void)
{
	ft_putendl("Error!");
	exit(1);
}

void	start_hooks(t_fractol *data)
{
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
	mlx_hook(data->win_ptr, 6, 0, julia_motion, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_press, NULL);
	mlx_loop(data->mlx_ptr);
}

void	start_fractal(int type_fractal)
{
	t_fractol	*data;

	data = init_data(type_fractal);
	init_window(data);
	get_threads(data);
	start_hooks(data);
}

void	type_of_fractal(char *s)
{
	if (ft_strcmp(s, "-1") == 0)
		start_fractal(1);
	if (ft_strcmp(s, "-2") == 0)
		start_fractal(2);
	if (ft_strcmp(s, "-3") == 0)
		start_fractal(3);
	if (ft_strcmp(s, "-4") == 0)
		start_fractal(4);
	if (ft_strcmp(s, "-5") == 0)
		start_fractal(5);
	if (ft_strcmp(s, "-6") == 0)
		start_fractal(6);
	if (ft_strcmp(s, "-7") == 0)
		start_fractal(7);
	if (ft_strcmp(s, "-8") == 0)
		start_fractal(8);
	if (ft_strcmp(s, "-9") == 0)
		start_fractal(9);
	else
		print_help();
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		type_of_fractal(argv[1]);
	else
		print_help();
	return (0);
}
