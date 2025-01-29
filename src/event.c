/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:53:46 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 10:27:55 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_event(int keycode, t_app *app)
{
	ft_printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit_program(app);
	else if (keycode == KEY_C)
	{
		app->color_shift = (app->color_shift + 1) % 3;
		app->is_update = FALSE;
	}
	else if (keycode == KEY_P)
	{
		app->is_update = FALSE;
	}
	else if (keycode == KEY_PLUS)
	{
		app->precision += 5;
		app->is_update = FALSE;
	}
	else if (keycode == KEY_MINUS)
	{
		app->precision -= 5;
		app->is_update = FALSE;
	}
	else if (keycode == KEY_R)
	{
		reset_fractal(app);
	}
	else if (keycode == KEY_LEFT)
	{
		app->offset_x -= 50;
		move(app, 0, -50);
	}
	else if (keycode == KEY_RIGHT)
	{
		app->offset_x += 50;
		move(app, 0, 50);
	}
	else if (keycode == KEY_UP)
	{
		app->offset_y -= 50;
		move(app, -50, 0);
	}
	else if (keycode == KEY_DOWN)
	{
		app->offset_y += 50;
		move(app, 50, 0);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_app *app)
{
	double	zoom_factor;

	if (button == MOUSE_SCROLL_UP)
	{
		zoom_factor = 1.1;
		app->zoom *= zoom_factor;
		zoom(app, zoom_factor, x, y);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		zoom_factor = 0.9;
		app->zoom *= zoom_factor;
		zoom(app, zoom_factor, x, y);
	}
	else
		return (0);
	app->offset_x += x + WIN_WIDTH / 2;
	app->offset_y += y + WIN_HEIGHT / 2;
	return (0);
}
