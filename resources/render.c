/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:02:02 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 18:04:18 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	get_scaled_x(t_data *img, int w)
{
	double	result;

	result = (w - img->width / 2) / (0.25 * img->zoom * img->width)
		+ img->x_move;
	return (result);
}

double	get_scaled_y(t_data *img, int h)
{
	double	result;

	h = img->height - h;
	result = (h - img->height / 2) / (0.25 * img->zoom * img->height)
		+ img->y_move;
	return (result);
}

void	print_error(void)
{
	print_str(ERROR_MESSAGE);
	exit(1);
}

int	handle_close(void)
{
	exit(1);
	return (0);
}
