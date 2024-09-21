/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:03:59 by aabashee          #+#    #+#             */
/*   Updated: 2024/09/21 14:36:46 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //how many bits are used in a single pixel in the image & 8 converts this to the number of bytes per pixel.
	*(unsigned int *) dst = color;
}

double	compute_x0(t_data *img, int w)
{
	double	result;

	result = (w - img->width / 2) //middle of the screen.
		/ (0.25 * img->zoom * img->width) + img->x_move; // zoom and shift along the x-axis (img->y_move) are applied.
	return (result);
}
//computes the imaginary part of the complex number
double	compute_y0(t_data *img, int h)
{
	double	result;

	result = (h - img->height / 2)
		/ (0.25 * img->zoom * img->height) + img->y_move;
	return (result);
}

void	ft_error(void)
{
	ft_putstr("Invalid Arguments\n");
	exit (1);
}

int	ft_close(void)
{
	exit (1);
	return (0);
}
