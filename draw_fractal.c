//
// Created by Brandy Hugo on 29/02/2020.
//

#include "fractol.h"

void    draw_fractol(t_fractol *data)
{
    int y; //the y coordinate will be the imaginary part.
    int  x; //  the x coordinate will represent the real part of its complex coordinates
    int iteration;
    t_complex min;   // borders of the image
    t_complex max;   // borders of the image
    t_complex factor;
    t_complex c; // for each pixel apply an iterated complex function, the pixel  at the lower right corner of the image has coordinates [ImageWidth-1, ImageHeight-1]
    int max_iteration;
    t_color		color;

    max  = data->max;
    min = data->min;
    factor = init_complex(
            ((max.re - min.re) * data->zoom) / (SIZE_WIN - 1),
            ((max.im - min.im)  * data->zoom) / (SIZE_WIN - 1));

    max_iteration = 50;

    y = data->start;
    while (y < data->finish)
    {
        c.im = max.im - y * factor.im;
        x = 0;
        while (x < (SIZE_WIN * data->bpp / 8))
        {
            c.re = min.re + x * factor.re;
            iteration = mandelbrot_function(c, max_iteration);
            color = get_color(iteration, max_iteration);
            put_pixel(data, x, y, color);
            x++;
        }
        y++;
    }
}

void     get_threads(t_fractol *data)
{
    pthread_t threads[NUM_THREADS];
    t_fractol data2[NUM_THREADS];
    int  i;
    int k;

    i = 0;
    k = (SIZE_WIN * data->bpp / 8)/ NUM_THREADS;
    printf("k %d\n", k);
    while (i < NUM_THREADS)
    {
        data2[i] = *data;
        data2[i].start = i * k;
        data2[i].finish = (i + 1) * k;
        printf("start %d\n",data2[i].start);
        printf("finish %d\n",data2[i].finish);
        if (pthread_create(&threads[i], NULL, (void *(*)(void *)) draw_fractol, (void *) &data2[i]))
            error_out();
        i++;
    }
    while (i-- > 0)
    {
        if (pthread_join(threads[i], NULL))
            error_out();
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
