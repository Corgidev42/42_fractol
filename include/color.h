/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:53:50 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:06:15 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "fractol.h"

/**
* @brief Génère une couleur en niveaux de gris en fonction de l'intensité donnée.
 *
 * @param t Un coefficient entre 0 et 1 définissant l'intensité du gris.
 * @return La couleur en format hexadécimal (0xRRGGBB).
 */
int	color_grayscale(double t);

/**
 * @brief Génère une couleur feu avec un dégradé allant du noir au rouge-orange.
 *
 * @param t Un coefficient entre 0 et 1 définissant l'intensité de la couleur.
 * @return La couleur en format hexadécimal (0xRRGGBB).
 */
int	color_fire(double t);

/**
 * @brief Génère une couleur froide avec un mélange de bleu et de vert.
 *
 * @param t Un coefficient entre 0 et 1 définissant l'intensité de la couleur.
 * @return La couleur en format hexadécimal (0xRRGGBB).
 */
int	color_cool(double t);

/**
 * @brief Génère une couleur coucher de soleil avec des tons chauds et atténués.
 *
 * @param t Un coefficient entre 0 et 1 définissant l'intensité de la couleur.
 * @return La couleur en format hexadécimal (0xRRGGBB).
 */
int	color_sunset(double t);

/**
 * @brief Génère une couleur océan avec des teintes de bleu et de vert.
 *
 * @param t Un coefficient entre 0 et 1 définissant l'intensité de la couleur.
 * @return La couleur en format hexadécimal (0xRRGGBB).
 */
int	color_ocean(double t);

#endif
