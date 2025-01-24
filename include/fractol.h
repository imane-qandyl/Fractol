/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:43:57 by imqandyl          #+#    #+#             */
/*   Updated: 2025/01/24 18:36:15 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ERROR_MESSAGE "Please enter:\n\t\"./fractol mandelbrot\"\
						or \n\t\"./fractol julia <value_1> <value_2>\""

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../include/mlx.h"

# define WIDTH   800
# define HEIGHT  800

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		flag;
	int		base_color;
	int		iteration;
	int		max_iteration;
	int		stop;
	double	xtemp;
	double	cx;
	double	cy;
	double	offset;
	double	x_move;
	double	y_move;
	double	zoom;
	double	x_axis;
	double	y_axis;
	char	name;
}	t_data;

// Function declarations with new names
void	render_mandelbrot(t_data *img);
void	render_julia(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	handle_arrow_keys(t_data *img, int keycode);
void	init_fractol(t_data *img, int ac, char **av);
int		handle_mouse(int mouse_key_code, int x, int y, t_data *img);
int		handle_keypress(int keycode, t_data *img);
int		handle_julia_mouse_move(int x, int y, t_data *img);
void	update_color(t_data *img, int color);
double	get_scaled_x(t_data *img, int w);
double	get_scaled_y(t_data *img, int h);
double	str_to_double(const char *str);
int		str_compare(const char *s1, const char *s2);
int		handle_close(void);
int		validate_number(const char *str1);
void	print_str(char *str);
void	print_error(void);

#endif
