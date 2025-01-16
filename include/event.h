/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:00 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/14 12:21:56 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "fractol.h"

/**
 * Handles keyboard events.
 *
 * @param keycode The code of the key that was pressed.
 * @param app A pointer to the application structure.
 * @return An integer indicating the result of the event handling.
 */
int keyboard_event(int keycode, t_app *app);

/**
 * Handles mouse events.
 *
 * @param button The button that was pressed.
 * @param x The x-coordinate of the mouse event.
 * @param y The y-coordinate of the mouse event.
 * @param app A pointer to the application structure.
 * @return An integer indicating the result of the event handling.
 */
int mouse_event(int button, int x, int y, t_app *app);

#endif
