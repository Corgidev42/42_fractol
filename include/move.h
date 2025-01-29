/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:07 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:08:16 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "fractol.h"

void	move_minus(t_app *app, int vertical, int horizontal);
void	move_plus(t_app *app, int vertical, int horizontal);
void	move(t_app *app, int vertical, int horizontal);
void	zoom(t_app *app, double zoom_factor);
void	apply_zoom(t_app *app, double zoom_factor);
double	ft_map(double unscaled_num, double old_min, double old_max,
		double new_min, double new_max);

#endif
