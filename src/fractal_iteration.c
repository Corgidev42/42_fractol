/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_iteration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:29:41 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 14:40:00 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship_iterations(double real, double imag, t_app *app)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while ((pow(z_re, 2) + pow(z_im, 2)) <= 4 && i < app->max_iter)
	{
		z_re = fabs(z_re);
		z_im = fabs(z_im);
		temp = pow(z_re, 2) - pow(z_im, 2) + real;
		z_im = 2 * z_re * z_im + imag;
		z_re = temp;
		i++;
	}
	return (i);
}

int	julia_iterations(double z_re, double z_im, t_app *app)
{
	int		i;
	double	temp;

	i = 0;
	while ((pow(z_re, 2) + pow(z_im, 2)) <= 4 && i < app->max_iter)
	{
		temp = pow(z_re, 2) - pow(z_im, 2) + app->julia_re;
		z_im = 2 * z_re * z_im + app->julia_im;
		z_re = temp;
		i++;
	}
	return (i);
}

int	mandelbrot_iterations(double real, double imag, t_app *app)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (pow(z_re, 2) + pow(z_im, 2) <= 4 && i < app->max_iter)
	{
		temp = pow(z_re, 2) - pow(z_im, 2) + real;
		z_im = 2 * z_re * z_im + imag;
		z_re = temp;
		i++;
	}
	return (i);
}
