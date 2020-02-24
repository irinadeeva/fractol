#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"

# define SIZE_WIN		1000
# define BOARD_ESC		53

typedef struct	s_fractol
{
    void		*mlx_ptr;
    void		*img_ptr;
    void		*win_ptr;
    int			*image_pix;
    int			bpp;
}				t_fractol;

#endif