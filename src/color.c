//
// Created by Brandy Hugo on 05/03/2020.
//

#include "fractol.h"


t_color	red_color(int iteration, int max_iteration)
{
    t_color	color;

    if (iteration == max_iteration)
    {
        color.channel[0] = 0;
        color.channel[1] = 0;
        color.channel[2] = 0;
        color.channel[3] = 0;
    }
    else
    {
        color.channel[0] = 0;
        color.channel[1] = 127;
        color.channel[2] = 0;
        color.channel[3] = 0;
    }
    return (color);
}

t_color	green_color(int iteration, int max_iteration)
{
    t_color	color;

    if (iteration == max_iteration)
    {
        color.channel[0] = 0;
        color.channel[1] = 0;
        color.channel[2] = 0;
        color.channel[3] = 0;
    }
    else
    {
        color.channel[0] = 0;
        color.channel[1] = 0;
        color.channel[2] = 127;
        color.channel[3] = 0;
    }
    return (color);
}

t_color	blue_color(int iteration, int max_iteration)
{
    t_color	color;

    if (iteration == max_iteration)
    {
        color.channel[0] = 0;
        color.channel[1] = 0;
        color.channel[2] = 0;
        color.channel[3] = 0;
    }
    else
    {
        color.channel[0] = 0;
        color.channel[1] = 0;
        color.channel[2] = 0;
        color.channel[3] = 127;
    }
    return (color);
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

t_color	get_color2(int iteration, int max_iteration)
{
    t_color	color;
    double	t;

    t = (double)iteration / max_iteration;
    color.channel[0] = 0;
    color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color.channel[3] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color.channel[2] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

t_color	get_color3(int iteration, int max_iteration)
{
    t_color	color;
    double	t;

    t = (double)iteration / max_iteration;
    color.channel[0] = 0;
    color.channel[3] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color.channel[1] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

t_color	get_color4(int iteration, int max_iteration)
{
    t_color	color;
    double	t;

    t = (double)iteration / max_iteration;
    color.channel[0] = 0;
    color.channel[2] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
    color.channel[1] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
    return (color);
}

t_color	continuous_colouring(int iteration, t_complex c)
{
    t_color	color;
    double continuous_index;
    double z;

    z = sqrt(c.re * c.re + c.im * c.im);
    continuous_index = iteration + 1 - (log(2) / fabs(z)) / log (2);
    color.channel[0] = 0;
    color.channel[3] = (unsigned char)(sin(0.017 * continuous_index + 4) * 230 + 25);
    color.channel[2] = (unsigned char)(sin(0.013 * continuous_index + 2) * 230 + 25);
    color.channel[1] = (unsigned char)(sin(0.02 * continuous_index + 1) * 230 + 25);
    return (color);
}

t_color choose_color(int iteration, int max_iteration, int type_color, t_complex c)
{
    t_color	color;

    color.channel[0] = 0;
    color.channel[1] = 0;
    color.channel[2] = 0;
    color.channel[3] = 0;
    if (type_color == 9)
        return(red_color(iteration, max_iteration));
    if (type_color == 2)
        return(blue_color(iteration, max_iteration));
    if (type_color == 3)
        return(green_color(iteration, max_iteration));
    if (type_color == 4)
        return(get_color(iteration, max_iteration));
    if (type_color == 5)
        return(get_color2(iteration, max_iteration));
    if (type_color == 6)
        return(get_color3(iteration, max_iteration));
    if (type_color == 7)
       return(get_color4(iteration, max_iteration));
    if (type_color == 8)
        return(get_color4(iteration, max_iteration));
    if (type_color == 1)
        return(continuous_colouring(iteration, c));
    else
        return (color);
}
