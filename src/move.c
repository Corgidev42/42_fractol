/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:50:02 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 10:58:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_plus(t_app *app, int vertical, int horizontal)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			dst = app->temp_addr + ((y + vertical) * app->line_length + (x
						+ horizontal) * (app->bits_per_pixel / 8));
			if (x + horizontal < WIN_WIDTH && y + vertical < WIN_HEIGHT)
			{
				put_pixel(app, x, y, *(unsigned int *)dst, 1);
			}
			else
				put_pixel(app, x, y, 0, 1);
			x++;
		}
		y++;
	}
}

void	move_minus(t_app *app, int vertical, int horizontal)
{
	int		x;
	int		y;
	char	*dst;

	y = WIN_HEIGHT - 1;
	while (y >= 0)
	{
		x = WIN_WIDTH - 1;
		while (x >= 0)
		{
			dst = app->temp_addr + ((y + vertical) * app->line_length + (x
						+ horizontal) * (app->bits_per_pixel / 8));
			if (x + horizontal >= 0 && y + vertical >= 0)
			{
				put_pixel(app, x, y, *(unsigned int *)dst, 1);
			}
			else
				put_pixel(app, x, y, 0, 1);
			x--;
		}
		y--;
	}
}

void	move(t_app *app, int vertical, int horizontal)
{
	if (vertical < 0 || horizontal < 0)
		move_minus(app, vertical, horizontal);
	else
		move_plus(app, vertical, horizontal);
	mlx_clear_window(app->mlx, app->win);
	mlx_put_image_to_window(app->mlx, app->win, app->temp_img, 0, 0);
}

void	zoom_out(t_app *app, double zoom_factor, int mouse_x, int mouse_y)
{
	char	*dst;

	int x, y;
	double new_x, new_y;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			new_x = (x - mouse_x) * zoom_factor + mouse_x;
			new_y = (y - mouse_y) * zoom_factor + mouse_y;
			if (new_x >= 0 && new_x < WIN_WIDTH && new_y >= 0
				&& new_y < WIN_HEIGHT)
			{
				dst = app->temp_addr + ((int)new_y * app->line_length
						+ (int)new_x * (app->bits_per_pixel / 8));
				put_pixel(app, x, y, *(unsigned int *)dst, 1);
			}
			else
			{
				put_pixel(app, x, y, 0, 1);
			}
			x++;
		}
		y++;
	}
}

void	zoom_in(t_app *app, double zoom_factor, int mouse_x, int mouse_y)
{
	char	*dst;

	int x, y;
	double new_x, new_y;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			new_x = (x - mouse_x) / zoom_factor + mouse_x;
			new_y = (y - mouse_y) / zoom_factor + mouse_y;
			if (new_x >= 0 && new_x < WIN_WIDTH && new_y >= 0
				&& new_y < WIN_HEIGHT)
			{
				dst = app->temp_addr + ((int)new_y * app->line_length
						+ (int)new_x * (app->bits_per_pixel / 8));
				put_pixel(app, x, y, *(unsigned int *)dst, 1);
			}
			else
			{
				put_pixel(app, x, y, 0, 1);
			}
			x++;
		}
		y++;
	}
}



void	zoom(t_app *app, double zoom_factor, int mouse_x, int mouse_y)
{
	if (zoom_factor > 1.0)
	{
		zoom_in(app, zoom_factor, mouse_x, mouse_y);
	}
	else
	{
		zoom_out(app, zoom_factor, mouse_x, mouse_y);
	}
	mlx_clear_window(app->mlx, app->win);
	mlx_put_image_to_window(app->mlx, app->win, app->temp_img, 0, 0);
}
