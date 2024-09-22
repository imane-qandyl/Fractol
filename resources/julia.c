/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:10:29 by aabashee          #+#    #+#             */
/*   Updated: 2024/09/22 08:10:42 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "fractol.h"

static void	algorithm(t_data *img, int w, int h)
{
	double	zx;
	double	zy;

	zx = compute_x0(img, w);
	zy = compute_y0(img, h);
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

void	show_julia(t_data *img)
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
