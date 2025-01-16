/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:31:31 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATION_H
# define ITERATION_H

# include "fractol.h"

/**
 * @brief Calculates the number of iterations for a point in the Mandelbrot set.
 *
 * This function determines how many iterations it takes for the given complex
 * number (represented by its real and imaginary parts) to escape the Mandelbrot
 * set, based on the parameters defined in the application context.
 *
 * @param real The real part of the complex number.
 * @param imag The imaginary part of the complex number.

	* @param app A pointer to the application context containing parameters for the iteration.
 * @return The number of iterations before the point escapes the Mandelbrot set.
 */
int	mandelbrot_iterations(double real, double imag, t_app *app);

/**
 * @brief Computes the number of iterations for the Julia set.
 *
 * This function calculates the number of iterations required for a given
 * complex number (z_re + z_im * i) to determine if it belongs to the Julia set.
 * The calculation is based on the parameters provided in the t_app structure.
 *
 * @param z_re The real part of the complex number.
 * @param z_im The imaginary part of the complex number.

	* @param app A pointer to the t_app structure containing the parameters for the Julia set.

	* @return The number of iterations before the complex number escapes the Julia set.
 */
int	julia_iterations(double z_re, double z_im, t_app *app);

/**
 * @brief Calculates the number of iterations for the Burning Ship fractal.
 *
 * This function computes the number of iterations required for a point in the

	* complex plane to escape the Burning Ship fractal set. The Burning Ship fractal
 * is similar to the Mandelbrot set but uses the absolute values of the real and
 * imaginary parts in its iteration formula.
 *
 * @param real The real part of the complex number.
 * @param imag The imaginary part of the complex number.
 * @param app A pointer to the application context, which may contain parameters
 *            such as the maximum number of iterations and escape radius.
 * @return The number of iterations before the point escapes, or the maximum
 *         number of iterations if the point does not escape.
 */
int	burning_ship_iterations(double real, double imag, t_app *app);

#endif
