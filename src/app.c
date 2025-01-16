/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:19:03 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:35:09 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	kill_app(t_app *app)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
}

void	Exit_Error(const char *message, t_app *app)
{
	perror(message);
	kill_app(app);
	exit(EXIT_FAILURE);
}

void	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		Exit_Error("Failed to initialize MLX", app);
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!app->win)
		Exit_Error("Failed to create window", app);
	app->img = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->img)
		Exit_Error("Failed to create image", app);
	app->addr = mlx_get_data_addr(app->img, &app->bits_per_pixel,
			&app->line_length, &app->endian);
	if (!app->addr)
		Exit_Error("Failed to access image data", app);
	app->zoom = 1.0;
	app->offset_x = 0;
	app->offset_y = 0;
	app->is_update = FALSE;
}

int	exit_program(t_app *app)
{
	kill_app(app);
	exit(EXIT_SUCCESS);
	return (0);
}

int	update_frame(t_app *app)
{
	if (app->is_update == FALSE)
	{
		if (app->fractal_type == MANDELBROT)
			render_fractal(app, mandelbrot_iterations);
		else if (app->fractal_type == JULIA)
			render_fractal(app, julia_iterations);
		else if (app->fractal_type == BURNING_SHIP)
			render_fractal(app, burning_ship_iterations);
		app->is_update = TRUE;
	}
	return (0);
}

void	fractal_app(t_app *app)
{
	init_app(app);
	mlx_hook(app->win, 17, 0, exit_program, app);
	mlx_key_hook(app->win, keyboard_event, app);
	mlx_mouse_hook(app->win, mouse_event, app);
	mlx_loop_hook(app->mlx, update_frame, app);
	mlx_loop(app->mlx);
}
