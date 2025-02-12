/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:10:39 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FRACTAL_H
# define RENDER_FRACTAL_H

# include "fractol.h"

/**

	* @brief Place un pixel d'une certaine couleur à une position donnée dans l'image.
 *
 *
	- Vérifie que le pixel est bien dans les limites de l'image avant de l'écrire.
 *
 * @param app Structure contenant les données de l'application,
	y compris l'image.
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @param color Couleur du pixel en format hexadécimal (0xRRGGBB).
 */
void	put_pixel(t_app *app, int x, int y, int color);

/**

	* @brief Génère une couleur en fonction du nombre d'itérations et du mode de coloration.
 *
 *
	- Différentes palettes de couleurs sont appliquées selon la valeur de color_shift.
 *
 * @param iter Nombre d'itérations effectuées avant divergence.
 * @param max_iter Nombre maximal d'itérations défini pour la fractale.
 * @param color_shift Indicateur de la palette de couleurs sélectionnée.
 * @return La couleur calculée en format hexadécimal (0xRRGGBB).
 */
int		get_color(int iter, int max_iter, int color_shift);

/**

	* @brief Traite un pixel donné en appliquant l'algorithme de la fractale et en assignant une couleur.
 *
 * - Calcule les coordonnées complexes associées au pixel.
 * - Applique la fonction d'itération pour déterminer la valeur de la fractale.
 * - Convertit l'itération en couleur et place le pixel dans l'image.
 *
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @param app Structure contenant les données de l'application.

	* @param iteration Pointeur vers la fonction d'itération spécifique à la fractale.
 */
void	process_pixel(int x, int y, t_app *app, int (*iteration)(double, double,
				t_app *));

/**
 * @brief Rendu complet de la fractale dans l'image, en traitant chaque pixel.
 *
 * - Parcourt toute l'image et applique l'algorithme de la fractale.
 * - Met à jour l'affichage de la fenêtre avec l'image générée.
 *
 * @param app Structure contenant les données de l'application.

	* @param iteration Pointeur vers la fonction d'itération spécifique à la fractale.
 * @return Toujours 0 (convention pour les hooks MLX).
 */
int		render_fractal(t_app *app, int (*iteration)(double, double, t_app *));

#endif
