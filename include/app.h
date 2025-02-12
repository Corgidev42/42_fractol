/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:25:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:05:22 by vbonnard         ###   ########.fr       */
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

/**
 * @brief Libère les ressources allouées et ferme proprement l'application.
 *
 * @param app Structure contenant les données de l'application.
 */
void		kill_app(t_app *app);

/**
 * @brief Initialise l'application et alloue les ressources nécessaires.
 *
 * @param app Structure contenant les données de l'application.
 */
void		init_app(t_app *app);

/**
 * @brief Quitte proprement le programme en libérant les ressources.
 *
 * @param app Structure contenant les données de l'application.
 * @return Toujours retourne 0 (convention pour les hooks MLX).
 */
int			exit_program(t_app *app);

/**
 * @brief Réinitialise les paramètres du fractal à leur état d'origine.
 *
 * @param app Structure contenant les données de l'application.
 */
void		reset_fractal(t_app *app);

/**
 * @brief Lance la boucle principale de l'application et gère les événements.
 *
 * @param app Structure contenant les données de l'application.
 */
void		fractal_app(t_app *app);

#endif
