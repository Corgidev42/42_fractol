/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:33 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 11:14:29 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iterations(double z_re, double z_im, t_app *app)
{
	int			i;
	double		temp;
	const int	max_iterations = 100;

	i = 0;
	while ((pow(z_re, 2) + pow(z_im, 2)) <= 4 && i < max_iterations)
	{
		temp = pow(z_re, 2) - pow(z_im, 2) + app->julia_re;
		z_im = 2 * z_re * z_im + app->julia_im;
		z_re = temp;
		i++;
	}
	return (i);
}

