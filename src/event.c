/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:53:46 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/15 14:27:16 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_event(int keycode, t_app *app)
{
	double	move_speed;

	move_speed = 0.05 / app->zoom;
	if (keycode == KEY_ESC)
		exit_program(app);
	else if (keycode == KEY_C)
	{
		app->color_shift = (app->color_shift + 1) % 3;
		app->is_update = FALSE;
	}
	else if (keycode == KEY_UP)
		app->offset_y -= move_speed;
	else if (keycode == KEY_DOWN)
		app->offset_y += move_speed;
	else if (keycode == KEY_LEFT)
		app->offset_x -= move_speed;
	else if (keycode == KEY_RIGHT)
		app->offset_x += move_speed;
	app->is_update = FALSE;
	return (0);
}

int	mouse_event(int button, int x, int y, t_app *app)
{
	double	zoom_factor;
	double	real;
	double	imag;

	zoom_factor = 1.1;
	pixel_to_complex(x, y, app, &real, &imag);
	if (button == MOUSE_SCROLL_UP)
	{
		app->zoom *= zoom_factor;
		app->offset_x = real - (real - app->offset_x) / zoom_factor;
		app->offset_y = imag - (imag - app->offset_y) / zoom_factor;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		app->zoom /= zoom_factor;
		app->offset_x = real - (real - app->offset_x) * zoom_factor;
		app->offset_y = imag - (imag - app->offset_y) * zoom_factor;
	}
	app->is_update = FALSE;
	return (0);
}
