/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:42 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:49:00 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*dst;

	dst = app->addr + (y * app->line_length + x * (app->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter, int color_shift)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	if (color_shift == 0)
	{
		red = (int)(9 * (1 - t) * pow(t, 3) * 255);
		green = (int)(15 * (1 - t) * (1 - t) * pow(t, 2) * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_shift == 1)
	{
		red = (int)(255 * t);
		green = (int)(255 * (1 - t));
		blue = (int)(255 * (1 - pow(t, 2)));
	}
	else
	{
		red = (int)(255 * fabs(sin(t * 3.14)));
		green = (int)(255 * fabs(cos(t * 3.14)));
		blue = (int)(255 * fabs(sin(t * 6.28)));
	}
	return ((red << 16) | (green << 8) | blue);
}

void	pixel_to_complex(int x, int y, t_app *app, double *real, double *imag)
{
	*real = (x - WIN_WIDTH / 2.0) / (app->zoom * WIN_WIDTH / 4) + app->offset_x;
	*imag = (y - WIN_HEIGHT / 2.0) / (app->zoom * WIN_HEIGHT / 4)
		+ app->offset_y;
}

int	render_fractal(t_app *app, int (*iteration)(double, double, t_app*))
{
	int		x;
	int		y;
	int		iter;
	double	real;
	double	imag;
	int		color;

	if (app->is_update == TRUE)
		return (0);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_to_complex(x, y, app, &real, &imag);
			iter = iteration(real, imag, app);
			color = get_color(iter, 100, app->color_shift);
			put_pixel(app, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(app->mlx, app->win);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	app->is_update = TRUE;
	return (0);
}
