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
#define NUM_THREADS 5

typedef	struct		s_color
{
    int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
    double			re;
    double			im;
}					t_complex;

typedef struct		s_mouse
{
    int button;
    int x;
    int y;
}					t_mouse;

typedef struct	s_fractol
{
    void		*mlx_ptr;
    void		*img_ptr;
    void		*win_ptr;
    char			*image_pix;
    int			bpp;
    int		    size_line;
    double         zoom;
    t_complex min;
    t_complex max;
    double    i;
    t_mouse *mouse;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
}				t_fractol;

int		key_hook(int keycode, t_fractol *data);
int		mouse_release_hook(int button, int x, int y, t_fractol *data);
int     mouse_hook(int button, int x,int y, t_fractol *data);
void    draw_fractol(t_fractol *data);
void	error_out(void);

#endif