/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:32:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 14:42:48 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_error(const char *message, t_app *app)
{
	perror(message);
	kill_app(app);
	exit(EXIT_FAILURE);
}

int	update_frame(t_app *app)
{
	if (app->fractal_type == MANDELBROT)
		render_fractal(app, mandelbrot_iterations);
	else if (app->fractal_type == JULIA)
		render_fractal(app, julia_iterations);
	else if (app->fractal_type == BURNING_SHIP)
		render_fractal(app, burning_ship_iterations);
	return (0);
}
