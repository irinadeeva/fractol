//
// Created by Brandy Hugo on 29/02/2020.
//

#include "fractol.h"


t_complex init_complex(double re, double im)
{
    t_complex complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}

void	put_pixel(t_fractol *data, int x, int y, t_color color)
{
    int	i;

    i = (x * data->bpp / 8) + (y * data->size_line);
    if (i < SIZE_WIN * data->size_line)
    {
        data->image_pix[i] = color.channel[3];
        data->image_pix[++i] = color.channel[2];
        data->image_pix[++i] = color.channel[1];
        data->image_pix[++i] = color.channel[0];
    }

}

t_color	get_color(int iteration, int max_iteration)
{
    t_color	color;
    double	t;

    t = (double)iteration / max_iteration;
    color.channel[0] = 0;
    color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

// So how to generate such a beautiful fractal?
// for every pixel, iterate znew = zold² + c on the complex plane until it leaves the circle around the origin with radius 2.
// The number of iterations it the color of the pixel.

int mandelbrot_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < max_iteration)
    {
        z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, 2.0 * z.re * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

int julia_function(t_complex c, int max_iteration, t_complex k)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < max_iteration)
    {
        z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + k.re,2.0 * z.re * z.im + k.im);
        iteration++;
    }
    return(iteration);
}

int burning_ship_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
                -2.0 * fabs(z.re * z.im) + c.im);
        iteration++;
    }
    return(iteration);
}

int mandelbar_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
                -2.0 * z.re * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

int celtic_mandelbrot_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,
                2.0 * z.re * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

int celtic_mandelbar_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,
                -2.0 * z.re * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

int celtic_perpendicular_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,
                -2.0 * fabs(z.re) * z.im + c.im);
        iteration++;
    }
    return(iteration);
}

int perpendicular_mandelbrot_function(t_complex c, int max_iteration)
{
    int iteration;
    t_complex z;

    z = init_complex(c.re, c.im);
    iteration = 0;
    while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
           && iteration < max_iteration)
    {
        z = init_complex(
                pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
                -2.0 * fabs(z.re) * z.im + c.im);
        iteration++;
    }
    return(iteration);
}


int choose_fractal(t_complex c, t_fractol *data)
{
    if (data->type_fractal == 1)
        return(mandelbrot_function(c, data->max_iteration));
    if (data->type_fractal == 2)
        return(julia_function(c, data->max_iteration, data->k));
    if (data->type_fractal == 3)
        return(burning_ship_function(c, data->max_iteration));
    if (data->type_fractal == 4)
        return(mandelbar_function(c, data->max_iteration));
    if (data->type_fractal == 5)
        return(celtic_mandelbrot_function(c, data->max_iteration));
    if (data->type_fractal == 6)
        return(celtic_mandelbar_function(c, data->max_iteration));
    if (data->type_fractal == 7)
        return(celtic_perpendicular_function(c, data->max_iteration));
    if (data->type_fractal == 8)
        return(perpendicular_mandelbrot_function(c, data->max_iteration));
    else
        return (0);
}


void    draw_fractol(t_fractol *data)
{
    int y; //the y coordinate will be the imaginary part.
    int  x; //  the x coordinate will represent the real part of its complex coordinates
    int iteration;
    t_complex min;   // borders of the image
    t_complex max;   // borders of the image
    t_complex factor; // ratio complex to (x;y) связь между комплексными числами и пикселями на экране
    t_complex c; // for each pixel apply an iterated complex function, the pixel  at the lower right corner of the image has coordinates [ImageWidth-1, ImageHeight-1]
    t_color		color;

    max  = data->max;
    min = data->min;
    factor = init_complex(
            ((max.re - min.re) ) / (SIZE_WIN - 1),
            ((max.im - min.im) ) / (SIZE_WIN - 1));

    y = data->start;
    while (y < data->finish)
    {
        c.im = max.im - y * factor.im; // считается особым образом. Это происходит по причине того, что ось y в окне программы направлена сверху вниз, а не снизу вверх как мы привыкли.
        x = 0;
        while (x < (SIZE_WIN * data->bpp / 8))
        {
            c.re = min.re + x * factor.re;
            iteration = choose_fractal(c, data);
            color = get_color(iteration, data->max_iteration);
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
    while (i < NUM_THREADS)
    {
        data2[i] = *data;
        data2[i].start = i * k;
        data2[i].finish = (i + 1) * k;
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
    if (SIZE_WIN == 1000)
        menu(data);
}
