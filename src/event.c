/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:53:46 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/05 01:07:35 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_event(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		exit_program(app);
	else if (keycode == KEY_C)
		app->color_shift = (app->color_shift + 1) % 5;
	else if (keycode == KEY_PLUS)
		app->max_iter += 5;
	else if (keycode == KEY_MINUS)
		app->max_iter -= 5;
	else if (keycode == KEY_R)
		reset_fractal(app);
	else if (keycode == KEY_LEFT)
		app->offset_x -= 50;
	else if (keycode == KEY_RIGHT)
		app->offset_x += 50;
	else if (keycode == KEY_UP)
		app->offset_y -= 50;
	else if (keycode == KEY_DOWN)
		app->offset_y += 50;
	app->is_update = FALSE;
	return (0);
}

int	mouse_event(int button, int x, int y, t_app *app)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		zoom_factor = 1.2;
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (0);
	app->zoom *= zoom_factor;
	app->offset_x *= zoom_factor;
	app->offset_y *= zoom_factor;
	app->is_update = FALSE;
	if (app->max_iter < ITERATIONS_MAX)
		app->max_iter += app->zoom;
	if (app->max_iter < 0)
		app->max_iter = 0;
	return (0);
}
