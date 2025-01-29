/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:53:50 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:55:40 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "fractol.h"

int	color_grayscale(double t);
int	color_fire(double t);
int	color_cool(double t);
int	color_sunset(double t);
int	color_ocean(double t);

#endif
