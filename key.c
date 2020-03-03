//
// Created by Brandy Hugo on 29/02/2020.
//

#include "fractol.h"


int		julia_motion(int x, int y, t_fractol *data)
{

        data->k = init_complex(
                4 * ((double)x / SIZE_WIN - 0.5),
                4 * ((double)(SIZE_WIN - y) / SIZE_WIN- 0.5));
    get_threads(data);
    return (0);
}

int     mouse_press(int button, int x,int y, t_fractol *data)
{
    t_complex min;   // borders of the image
    t_complex max;   // borders of the image
    t_complex factor;
    t_complex c;

    if (data->type_fractal == 2)
        julia_motion(x,y, data);
    if ( button == 4)
        data->zoom = 0.8;
    if ( button == 5)
        data->zoom = 1.2;
    max  = data->max;
    min = data->min;
    factor = init_complex(
            ((max.re - min.re) * data->zoom) / (SIZE_WIN - 1),
            ((max.im - min.im)  * data->zoom) / (SIZE_WIN - 1));
    c.im = max.im - y * factor.im;
    c.re = min.re + x * factor.re;

    data->min.re = (data->min.re - c.re) * (1.0 / data->zoom) + c.re;
    data->min.im = (data->min.im - c.im) * (1.0 / data->zoom) + c.im;
    data->max.re = (data->max.re - c.re)* (1.0 / data->zoom) + c.re;
    data->max.im = data->min.im + (data->max.re - data->min.re) * SIZE_WIN / SIZE_WIN;

    printf("%d\n", y);
    printf("min.re %f\n", data->min.re);
    printf("max.re %f\n", data->max.re);
    printf("min.im %f\n", data->min.im);
    printf("max.im %f\n", data->max.im);

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

int		key_hook(int keycode, t_fractol *data)
{
    if (keycode == BOARD_ESC)
        exit(1);
    return (0);
}