/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:42 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:55:56 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = app->addr + (y * app->line_length + x * (app->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

int	get_color(int iter, int max_iter, int color_shift)
{
	if (iter == max_iter)
		return (0x000000);
	double t = (double)iter / max_iter;

	if (color_shift == 0)
		return color_grayscale(t);
	else if (color_shift == 1)
		return color_fire(t);
	else if (color_shift == 2)
		return color_cool(t);
	else if (color_shift == 3)
		return color_sunset(t);
	else if (color_shift == 4)
		return color_ocean(t);
	else
		return color_grayscale(t);
}

void	pixel_to_complex(int x, int y, t_app *app, double *real, double *imag)
{
	*real = (x + app->offset_x - WIN_WIDTH / 2.0) / (app->zoom * WIN_WIDTH / 4);
	*imag = (y + app->offset_y - WIN_HEIGHT / 2.0) / (app->zoom * WIN_HEIGHT
			/ 4);
}

void	process_pixel(int x, int y, t_app *app, int (*iteration)(double, double, t_app *))
{
	double real, imag;
	int iter, color;

	pixel_to_complex(x, y, app, &real, &imag);
	iter = iteration(real, imag, app);
	color = get_color(iter, app->max_iter, app->color_shift);
	put_pixel(app, x, y, color);
}

int	render_fractal(t_app *app, int (*iteration)(double, double, t_app *))
{
	int x, y;

	if (app->is_update == TRUE)
		return (0);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			process_pixel(x, y, app, iteration);
			x++;
		}
		y++;
	}
	app->is_update = TRUE;
	mlx_clear_window(app->mlx, app->win);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	return (0);
}
