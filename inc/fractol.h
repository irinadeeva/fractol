/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:24:38 by bhugo             #+#    #+#             */
/*   Updated: 2020/03/06 17:52:40 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <pthread.h>

# define SIZE_WIN			1000
# define BOARD_ESC			53
# define BOARD_PLUS			24
# define BOARD_MINUS		27
# define NUM_THREADS		4
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define BROAD_SPACE		49
# define BOARD_PLUS			24
# define BOARD_MINUS		27
# define PAD_PLUS			69
# define PAD_MINUS			78
# define BOARD_C			8
# define BOARD_V			9
# define TEXT				"- - - - MENU - - - -"
# define TEXT1				"arrows : shift"
# define TEXT2				"+ / -  : iterations"
# define TEXT3				"space  : default set"
# define TEXT4				"V      : fractol"
# define TEXT5				"C      : color"
# define TEXT9				"<esc>  : quit"
# define WHITE				0xFFFFFF
# define BLACK				0x000000

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*img_ptr;
	void			*win_ptr;
	char			*image_pix;
	int				bpp;
	int				size_line;
	double			zoom;
	int				type_fractal;
	int				type_color;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		k;
	int				start;
	int				finish;
}					t_fractol;

int					key_hook(int keycode, t_fractol *data);
int					mouse_release_hook(int button, int x,
		int y, t_fractol *data);
int					mouse_press(int button, int x, int y, t_fractol *data);
int					mouse_hook(int button, int x, int y, t_fractol *data);
int					julia_motion(int x, int y, t_fractol *data);
void				draw_fractol(t_fractol *data);
void				error_out(void);
t_complex			init_complex(double re, double im);
int					mandelbrot_function(t_complex c,
		int max_iteration, t_complex k);
void				put_pixel(t_fractol *data, int x, int y, t_color color);
void				get_threads(t_fractol *data);
void				menu(t_fractol *data);
void				print_help(void);
t_fractol			*init_data(int type_fractal);
void				init_window(t_fractol *data);
int					exit_press(void);
int					mandelbrot_function(t_complex c,
		int max_iteration, t_complex k);
int					julia_function(t_complex c, int max_iteration, t_complex k);
int					burning_ship_function(t_complex c,
		int max_iteration, t_complex k);
int					mandelbar_function(t_complex c,
		int max_iteration, t_complex k);
int					celtic_mandelbrot_function(t_complex c,
		int max_iteration, t_complex k);
int					celtic_perpendicular_function(t_complex c,
		int max_iteration, t_complex k);
int					celtic_mandelbar_function(t_complex c,
		int max_iteration, t_complex k);
int					perpendicular_mandelbrot(t_complex c,
		int max_iteration, t_complex k);
int					newton_function(t_complex c, int max_iteration);
t_color				choose_color(int iteration, int max_iteration,
		int type_color, t_complex c);
t_color				continuous_colouring(int iteration, t_complex c);
t_color				continuous_colouring2(int iteration, t_complex c);
t_color				get_color(int iteration, int max_iteration);
t_color				get_color2(int iteration, int max_iteration);
t_color				get_color3(int iteration, int max_iteration);
t_color				get_color4(int iteration, int max_iteration);

#endif
