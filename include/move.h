/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:07 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/28 17:51:04 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "fractol.h"

void	move_minus(t_app *app, int vertical, int horizontal);
void	move_plus(t_app *app, int vertical, int horizontal);
void	move(t_app *app, int vertical, int horizontal);
void	zoom(t_app *app, double zoom_factor, int mouse_x, int mouse_y);
void	zoom_out(t_app *app, double zoom_factor, int mouse_x, int mouse_y);
void	zoom_in(t_app *app, double zoom_factor, int mouse_x, int mouse_y);

#endif
