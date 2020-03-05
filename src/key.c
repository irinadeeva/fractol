//
// Created by Brandy Hugo on 29/02/2020.
//

#include "fractol.h"


int		julia_motion(int x, int y, t_fractol *data)
{

    data->k = init_complex(
                4 * ((double)x / SIZE_WIN - 0.5),
                4 * ((double)(SIZE_WIN - y) / SIZE_WIN - 0.5));
    get_threads(data);
    return (0);
}

int     mouse_press(int button, int x,int y, t_fractol *data)
{
    t_complex min;   // borders of the image
    t_complex max;   // borders of the image
    t_complex factor;
    t_complex c;
    double zoom;

     max = data->max;
     min = data->min;
     factor = init_complex(
             (max.re - min.re) / (SIZE_WIN - 1),
             (max.im - min.im) / (SIZE_WIN - 1));
     c.im = max.im - y * factor.im;
     c.re = min.re + x * factor.re;
     if (button == 1 || button == 4)
         zoom = 0.9f;
     if (button == 2 || button == 5)
         zoom = 1.1f;
     data->zoom *=zoom;
     if (data->zoom >=2)
         return (0);
     data->min.re = (min.re - c.re) * (zoom) + c.re;
     data->min.im = (min.im - c.im) * (zoom) + c.im;
     data->max.re = (max.re - c.re) * (zoom) + c.re;
     data->max.im = data->min.im + (data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
     get_threads(data);
     return (0);
}


//int		mouse_release_hook(int button, int x, int y, t_fractol *data)
//{
//
//    //    t_mouse *mouse;
//
//
//    if (!(mouse = (t_mouse *)malloc(sizeof(*mouse))))
//        error_out();
//    mouse->button = button;
//    mouse->x = x;
//    mouse->y = y;
//    data->mouse = mouse;
//    if (button == 1 || button == 4)
//        data->zoom = data->zoom * 0.8;
//    if (button == 2 || button == 5)
//        data->zoom = data->zoom * 1.2;
// get_threads(data);
//    return (0);
//}

void    set_default(t_fractol *data)
{
    data->min = init_complex(-2, -2);
    data->max.re = 2;
    data->max.im = data->min.im + (data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;
    data->zoom = 1;
    data->max_iteration = 50; // Чем больше будет указанное число, тем точнее будет полученное изображение фрактала. И тем больше вычислительных задач ляжет на компьютер.
    data->k = init_complex(-0.4, 0.6);
}

# define BROAD_SPACE 49
# define BOARD_PLUS		    24
# define BOARD_MINUS		27
# define PAD_PLUS		    69
# define PAD_MINUS		    78

int		key_hook(int keycode, t_fractol *data)
{
    if (keycode == BOARD_ESC)
        exit(1);
    if (keycode == BROAD_SPACE)
        set_default(data);
    if ((keycode == PAD_PLUS || keycode == BOARD_PLUS) && data->max_iteration < 150)
        data->max_iteration += 10;
    if ((keycode == PAD_MINUS || keycode == BOARD_MINUS) && data->max_iteration > 10)
        data->max_iteration -= 10;
    get_threads(data);
    return (0);
}

int		exit_press(void)
{
    exit(1);
    return (0);
}
