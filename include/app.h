/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:25:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 14:44:15 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "fractol.h"

typedef struct s_app
{
	void	*mlx;
	void	*win;
	int		fractal_type;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_iter;
	int		is_update;
	int		color_shift;
	double	julia_re;
	double	julia_im;
	double	zoom;
	int		offset_x;
	int		offset_y;
}			t_app;

void		reset_fractal(t_app *app);
void		init_app(t_app *app);
void		kill_app(t_app *app);
void		fractal_app(t_app *app);
int			exit_program(t_app *app);

#endif
