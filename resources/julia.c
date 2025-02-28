/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:31 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 18:02:35 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algorithm(t_data *img, int w, int h)
{
	double	zx;
	double	zy;

	zx = get_scaled_x(img, w);
	zy = get_scaled_y(img, h);
	img->xtemp = 0.0;
	img->iteration = 0;
	img->max_iteration = 500;
	while (zx * zx + zy * zy < 2 * 2 && img->iteration < img->max_iteration)
	{
		img->xtemp = zx * zx - zy * zy;
		zy = 2.0 * zx * zy + img->cy;
		zx = img->xtemp + img->cx;
		img->iteration += 1;
	}
	if (img->iteration == img->max_iteration)
		my_mlx_pixel_put(img, w, h, img->base_color);
	else
		my_mlx_pixel_put(img, w, h, img->base_color * img->iteration);
}

void	render_julia(t_data *img)
{
	int	h;
	int	w;

	h = 0;
	while (h < img->height)
	{
		w = 0;
		while (w < img->width)
		{
			algorithm(img, w, h);
			w++;
		}
		h++;
	}
}
