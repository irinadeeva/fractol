//
// Created by Brandy Hugo on 29/02/2020.
//

#include "fractol.h"

int     mouse_hook(int button, int x,int y, t_fractol *data)
{
    printf("%d\n", button);
    printf("%d\n", button);
    printf("%d\n", button);
    return (0);
}

int		mouse_release_hook(int button, int x, int y, t_fractol *data)
{
    t_mouse *mouse;


    if (!(mouse = (t_mouse *)malloc(sizeof(*mouse))))
        error_out();
    printf("%d\n", button);
    printf("%d\n", x);
    printf("%d\n", y);
    mouse->button = button;
    mouse->x = x;
    mouse->y = y;
    data->mouse = mouse;
    if (button == 1)
        data->zoom = data->zoom * 0.8;
    if (button == 2)
        data->zoom = data->zoom * 1.2;
    draw_fractol(data);
    return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
    if (keycode == BOARD_ESC)
        exit(1);
    return (0);
}