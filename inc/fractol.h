#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"
#include <pthread.h>

# define SIZE_WIN		1000
# define BOARD_ESC		53
# define BOARD_PLUS		    24
# define BOARD_MINUS	27
#define NUM_THREADS 4

typedef	struct		s_color
{
    int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
    double			re;
    double			im;
}					t_complex;

typedef struct	s_fractol
{
    void		*mlx_ptr;
    void		*img_ptr;
    void		*win_ptr;
    char		*image_pix;
    int			bpp;
    int		    size_line;
    double      zoom;
    int         type_fractal;
    int max_iteration;
    t_complex min;
    t_complex max;
    t_complex k;
    int     start;
    int     finish;


}				t_fractol;

int		    key_hook(int keycode, t_fractol *data);
int		    mouse_release_hook(int button, int x, int y, t_fractol *data);
int         mouse_press(int button, int x,int y, t_fractol *data);
int         mouse_hook(int button, int x,int y, t_fractol *data);
int		julia_motion(int x, int y, t_fractol *data);
void        draw_fractol(t_fractol *data);
void	    error_out(void);
t_complex   init_complex(double re, double im);
int         mandelbrot_function(t_complex c, int max_iteration);
t_color	    get_color(int iteration, int max_iteration);
void	    put_pixel(t_fractol *data, int x, int y, t_color color);
void        get_threads(t_fractol *data);
void	menu(t_fractol *data);
t_fractol  *init_data(int type_fractal);
int	exit_press(void);

#endif