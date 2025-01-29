/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:25:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/29 13:54:34 by vbonnard         ###   ########.fr       */
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

/**
 * @brief Exits the program with an error message.
 *
 * @param message The error message to display.
 * @param app The application context.
 */
void		Exit_Error(const char *message, t_app *app);

/**
 * @brief Initializes the application.
 *
 * @param app The application context to initialize.
 */
void		init_app(t_app *app);

/**
 * @brief Cleans up and terminates the application.
 *
 * @param app The application context to terminate.
 */
void		kill_app(t_app *app);

/**
 * @brief Runs the fractal application.
 *
 * @param app The application context.
 */
void		fractal_app(t_app *app);

/**
 * @brief Handles the program exit routine.
 *
 * @param app The application context.
 * @return int Status code for the exit routine.
 */
int			exit_program(t_app *app);

/**
 * @brief Updates the frame of the application.
 *
 * This function is responsible for updating the frame of the application.
 * It typically involves rendering the current state of the application
 * and handling any necessary updates to the display.
 *
 * @param app A pointer to the application structure.
 * @return An integer indicating the success or failure of the update operation.
 */
int			update_frame(t_app *app);

#endif
