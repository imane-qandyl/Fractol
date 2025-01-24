/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:25 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 18:37:15 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_data *img)
{
	img->width = WIDTH;
	img->height = HEIGHT;
	img->base_color = 0xFF00FFFF;
	img->flag = 0;
	img->zoom = 1;
	img->x_move = 0;
	img->y_move = 0;
	img->stop = 0;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->width, img->height, "fractol");
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_fractol(t_data *img, int argc, char **argv)
{
	init_values(img);
	if (argc == 4 && str_compare(argv[1], "julia") == 0)
	{
		if (validate_number(argv[2]) == 0 || validate_number(argv[3]) == 0)
			print_error();
		img->cx = str_to_double(argv[2]);
		img->cy = str_to_double(argv[3]);
		if (img->cx < -2.0 || img->cx > 2.0 || img->cy < -2.0 || img->cy > 2.0)
			print_error();
		img->flag = 0;
	}
	else if (argc == 2 && str_compare(argv[1], "mandelbrot") == 0)
		img->flag = 1;
	else
	{
		print_str("Please enter:\n\t\"./fractol mandelbrot\"\
			or \n\t\"./fractol julia <value_1> <value_2>\"");
		exit(EXIT_FAILURE);
	}
}

void	visualize(t_data *img)
{
	if (img->flag == 0)
		render_julia(img);
	else if (img->flag == 1)
		render_mandelbrot(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc > 1 && argc <= 4)
	{
		init_fractol(&img, argc, argv);
		visualize(&img);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
		mlx_hook(img.mlx_win, 2, 5, handle_keypress, &img);
		mlx_mouse_hook(img.mlx_win, handle_mouse, &img);
		mlx_hook(img.mlx_win, 6, 1L < 6, handle_julia_mouse_move, &img);
		mlx_hook(img.mlx_win, 17, 1L << 17, handle_close, 0);
		mlx_loop(img.mlx);
	}
	else
		print_error();
	return (0);
}
