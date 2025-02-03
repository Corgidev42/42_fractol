/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/31 16:20:57 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FRACTAL_H
# define RENDER_FRACTAL_H

# include "fractol.h"

void	put_pixel(t_app *app, int x, int y, int color);
int		get_color(int iter, int max_iter, int color_shift);
void	process_pixel(int x, int y, t_app *app,
			int (*iteration)(double, double, t_app *));
int		render_fractal(t_app *app, int (*iteration)(double, double, t_app *));

#endif
