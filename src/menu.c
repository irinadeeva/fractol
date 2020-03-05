//
// Created by Brandy Hugo on 04/03/2020.
//

#include "fractol.h"

# define TEXT				"- - - - MENU - - - -"
# define TEXT1				"arrows : shift"
# define TEXT2				"+ / -  : zoom"
# define TEXT3				"enter  : projection"
# define TEXT4				"Z / X  : height"
# define TEXT5				"C / V  : color"
# define TEXT6				"1 / 9  : rotation X"
# define TEXT7				"2 / 8  : rotation Y"
# define TEXT8				"3 / 7  : rotation Z"
# define TEXT9				"<esc>  : quit"



void	menu(t_fractol *data)
{
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 0, 0xFFFFFF, TEXT);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 30, 0xFFFFFF, TEXT1);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 60, 0xFFFFFF, TEXT2);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 90, 0xFFFFFF, TEXT3);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 120, 0xFFFFFF, TEXT4);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 150, 0xFFFFFF, TEXT5);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 180, 0xFFFFFF, TEXT6);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 210, 0xFFFFFF, TEXT7);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 240, 0xFFFFFF, TEXT8);
    //mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 270, 0xFFFFFF, TEXT9);
}