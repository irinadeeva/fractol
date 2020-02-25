#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"

# define SIZE_WIN		500
# define BOARD_ESC		53

typedef struct	s_fractol
{
    void		*mlx_ptr;
    void		*img_ptr;
    void		*win_ptr;
    char			*image_pix;
    int			bpp;
    int		    size_line;
}				t_fractol;

typedef struct		s_complex
{
    double			re;
    double			im;
}					t_complex;

typedef	struct		s_color
{
    int8_t			channel[4];
}					t_color;

#endif