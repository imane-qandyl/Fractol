/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycontrols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:11:09 by aabashee          #+#    #+#             */
/*   Updated: 2024/09/21 17:42:43 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "fractol.h"

// handles mouse events
int	mouse(int mouse_key_code, int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (mouse_key_code == 5) // Scroll up (zoom in)
	{
		img->zoom *= 1.1; // Increases zoom level by 10%
		img->y_move += (y - img->height / 2) * 0.0005 / img->zoom;
		img->x_move += (x - img->width / 2) * 0.0005 / img->zoom;
	}
	if (mouse_key_code == 4) //Scroll down (zoom out)
	{
		img->y_move += (y - img->height / 2) * 0.0005 / img->zoom;
		img->x_move += (x - img->width / 2) * 0.0005 / img->zoom;
		img->zoom /= 1.1;// Decreases zoom level by 10%
	}
	if (img->flag == 0)
		show_julia(img);
	else if (img->flag == 1)
		show_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	mouse_julia(int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (img->stop == 0) //the fractal is not paused ,meaning that the fractal can be zoomed into or out of and moved around while still responding to the mouse movements.
		img->cy = (x - img->width / 2)
			/ (0.25 * img->zoom * img->width) + img->x_move;
	if (img->stop == 0)
		img->cx = (y - img->height / 2)
			/ (0.25 * img->zoom * img->height) + img->y_move;
	if (img->flag == 0)
		show_julia(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0); // Update the image in the window
	return (0);
}
/*Right (D/→): Moves right.
Left (A/←): Moves left.
Up (W/↑): Moves up.
Down (S/↓): Moves down.*/
void	arrow_move(t_data *img, int keycode)
{
	if (keycode == 2 || keycode == 124)
		img->x_move += -0.1 / img->zoom;
	if (keycode == 0 || keycode == 123)
		img->x_move += 0.1 / img->zoom;
	if (keycode == 13 || keycode == 126)
		img->y_move += 0.1 / img->zoom;
	if (keycode == 1 || keycode == 125)
		img->y_move += -0.1 / img->zoom;
}

void	color_change(t_data *img, int color)
{
	img->base_color = color;
}
//Escape key (53): Closes the window and exits the program.
//Keys 1, 2, 3 (18, 19, 20): Change the base color of the fractal.
//Spacebar (49): Stops the Julia set 
//Enter (36): Reestart the Julia.
//arrow_move: Move the view around  

int	keypad(int keycode, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53) // escape key
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	else if (keycode == 49)
		img->stop = 1;
	else if (keycode == 36)
		img->stop = 0;
	arrow_move(img, keycode);
	if (img->flag == 0)
		show_julia(img);
	else if (img->flag == 1)
		show_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
