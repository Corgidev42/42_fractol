/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:19:03 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:23:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	kill_app(t_app *app)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
		free(app->mlx);
}

void	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		exit_error("Failed to initialize MLX", app);
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!app->win)
		exit_error("Failed to create window", app);
	app->img = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!app->img)
		exit_error("Failed to create image", app);
	app->addr = mlx_get_data_addr(app->img, &app->bits_per_pixel,
			&app->line_length, &app->endian);
	if (!app->addr)
		exit_error("Failed to access image data", app);
	app->offset_x = 0;
	app->offset_y = 0;
	app->color_shift = 0;
	app->endian = 0;
	app->zoom = 1.0;
	app->is_update = FALSE;
	app->max_iter = ITERATIONS_MAX;
}

int	exit_program(t_app *app)
{
	kill_app(app);
	exit(EXIT_SUCCESS);
	return (0);
}

void	reset_fractal(t_app *app)
{
	app->offset_x = 0;
	app->offset_y = 0;
	app->zoom = 1.0;
	app->max_iter = ITERATIONS_MAX;
	app->is_update = FALSE;
	update_frame(app);
}

void	fractal_app(t_app *app)
{
	mlx_hook(app->win, 17, 0, exit_program, app);
	mlx_key_hook(app->win, keyboard_event, app);
	mlx_mouse_hook(app->win, mouse_event, app);
	mlx_loop_hook(app->mlx, update_frame, app);
	mlx_loop(app->mlx);
}
