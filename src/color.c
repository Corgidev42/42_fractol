/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:53:36 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 14:33:40 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_grayscale(double t)
{
	int	shade;

	shade = (int)((1 - t) * 255);
	return ((shade << 16) | (shade << 8) | shade);
}

int	color_fire(double t)
{
	int	red ;
	int	green;
	int	blue;

	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * (1 - t) * (1 - t) * pow(t, 2) * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	color_cool(double t)
{
	int	red ;
	int	green;
	int	blue;

	red = (int)(255 * t);
	green = (int)(255 * (1 - t));
	blue = (int)(255 * (1 - pow(t, 2)));
	return ((red << 16) | (green << 8) | blue);
}

int	color_sunset(double t)
{
	int	red ;
	int	green;
	int	blue;

	red = (int)(255 * pow(t, 0.5));
	green = (int)(128 * (1 - t));
	blue = (int)(64 * pow(1 - t, 2));
	return ((red << 16) | (green << 8) | blue);
}

int	color_ocean(double t)
{
	int	red ;
	int	green;
	int	blue;

	red = (int)(64 * pow(1 - t, 3));
	green = (int)(128 * pow(t, 0.8));
	blue = (int)(255 * pow(t, 0.5));
	return ((red << 16) | (green << 8) | blue);
}
