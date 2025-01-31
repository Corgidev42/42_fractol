/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:47:45 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FRACTAL_H
# define RENDER_FRACTAL_H

# include "fractol.h"

void	put_pixel(t_app *app, int x, int y, int color);
int		get_color(int iter, int max_iter, int color_shift);
void	process_pixel(int x, int y, t_app *app, int (*iteration)(double, double, t_app *));
void	pixel_to_complex(int x, int y, t_app *app, double *real, double *imag);
int		render_fractal(t_app *app, int (*iteration)(double, double, t_app *));

#endif
