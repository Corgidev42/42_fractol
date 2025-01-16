/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:26:07 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:15:57 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship_iterations(double real, double imag, t_app *app)
{
	double		z_re;
	double		z_im;
	double		temp;
	int			i;
	const int	max_iterations = 100;

	z_re = 0;
	z_im = 0;
	i = 0;
	while ((pow(z_re, 2) + pow(z_im, 2)) <= 4 && i < max_iterations)
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
