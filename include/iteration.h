/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:42 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATION_H
# define ITERATION_H

# include "fractol.h"

int	mandelbrot_iterations(double real, double imag, t_app *app);

int	julia_iterations(double z_re, double z_im, t_app *app);

int	burning_ship_iterations(double real, double imag, t_app *app);

#endif
