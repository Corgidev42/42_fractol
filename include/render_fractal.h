/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:39:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "fractol.h"

/**
 * @file render_fractal.h
 * @brief Header file containing function declarations for rendering fractals.
 */

/**
 * @brief Get the color for a given iteration.
 *
 * @param iter The current iteration.
 * @param max_iter The maximum number of iterations.
 * @param color_shift The color shift value.
 * @return The color value.
 */
int		get_color(int iter, int max_iter, int color_shift);

/**
 * @brief Convert pixel coordinates to complex plane coordinates.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param app The application context.
 * @param real Pointer to store the real part of the complex number.
 * @param imag Pointer to store the imaginary part of the complex number.
 */
void	pixel_to_complex(int x, int y, t_app *app, double *real, double *imag);

/**
 * @brief Renders the fractal using the provided iteration function.
 *
 * This function takes an application context and an iteration function pointer

	* to render the fractal. The iteration function determines the number of iterations
 * for each point in the fractal.
 *
 * @param app Pointer to the application context.

	* @param iteration Function pointer to the iteration function. The iteration function

	*        takes two double parameters representing the coordinates and a pointer to the
 *        application context,
	and returns an integer representing the number of iterations.
 *

	* @return int Status code indicating success or failure of the rendering process.
 */
int		render_fractal(t_app *app, int (*iteration)(double, double, t_app *));

#endif
