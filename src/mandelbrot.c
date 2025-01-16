/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:32:15 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:16:04 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double real, double imag, t_app *app)
{
	double		z_re;
	double		z_im;
	double		temp;
	int			i;
	const int	max_iterations = 100;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (pow(z_re, 2) + pow(z_im, 2) <= 4 && i < max_iterations)
	{
		temp = pow(z_re, 2) - pow(z_im, 2) + real;
		z_im = 2 * z_re * z_im + imag;
		z_re = temp;
		i++;
	}
	return (i);
}
