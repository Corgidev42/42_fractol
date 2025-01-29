/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:53:42 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 10:59:00 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_app *app, int x, int y, int color, int use_temp)
{
	char	*dst;

	if (use_temp == 1)
		dst = app->temp_addr + (y * app->line_length + x * (app->bits_per_pixel / 8));
	else if (use_temp == 0)
	{
		dst = app->addr + (y * app->line_length + x * (app->bits_per_pixel / 8));
	}
	else
		return ;
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

int	get_grayscale(int iter, int max_iter)
{
	double	t;
	int		shade;

	if (iter == max_iter)
		return (0x000000); // Noir si on atteint la limite d'itérations
	t = (double)iter / max_iter;
	shade = (int)((1 - t) * 255); // Plus l'itération est élevée, plus la couleur est sombre
	return ((shade << 16) | (shade << 8) | shade); // Gris uniforme (R=G=B)
}

void	pixel_to_complex(int x, int y, t_app *app, double *real, double *imag)
{
	*real = (x + app->offset_x - WIN_WIDTH / 2.0) / (app->zoom * WIN_WIDTH / 4);
	*imag = (y + app->offset_y - WIN_HEIGHT / 2.0) / (app->zoom * WIN_HEIGHT / 4);
}

int	render_fractal(t_app *app, int (*iteration)(double, double, t_app *))
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
			// color = get_color(iter, 100, app->color_shift);
			color = get_grayscale(iter, app->precision);
			put_pixel(app, x, y, color, 1);
			put_pixel(app, x, y, color, 0);
			x++;
		}
		y++;
	}
	mlx_clear_window(app->mlx, app->win);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	app->is_update = TRUE;
	return (0);
}
