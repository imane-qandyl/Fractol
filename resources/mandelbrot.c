/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:55 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 18:05:01 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algorithm(t_data *img, int w, int h)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	img->xtemp = 0.0;
	img->iteration = 0;
	img->max_iteration = 50;
	img->offset = 0.05;
	while (x * x + y * y < 2 * 2 && img->iteration < img->max_iteration)
	{
		img->xtemp = x * x - y * y + get_scaled_x(img, w);
		y = 2.0 * x * y + get_scaled_y(img, h);
		x = img->xtemp;
		img->iteration += 1;
	}
	if (img->iteration == img->max_iteration)
		my_mlx_pixel_put(img, w, h, img->base_color);
	else
		my_mlx_pixel_put(img, w, h, img->base_color * img->iteration);
}

void	render_mandelbrot(t_data *img)
{
	int	h;
	int	w;

	h = 5;
	while (h < img->height)
	{
		w = 5;
		get_scaled_y(img, h);
		while (w < img->width)
		{
			algorithm(img, w, h);
			w++;
		}
		h++;
	}
}
