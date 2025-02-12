/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:00 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:07:59 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "fractol.h"

/**
 * @brief Gère les événements clavier pour contrôler la fractale.
 *
 * - Échap (ESC) : Quitte le programme.
 * - C : Change le mode de couleur (rotation parmi 5 modes).
 * - + : Augmente le nombre maximal d'itérations de 5.
 * - - : Diminue le nombre maximal d'itérations de 5.
 * - R : Réinitialise la fractale aux paramètres initiaux.
 * - Flèches directionnelles : Déplace la vue de la fractale.
 *
 * @param keycode Code de la touche enfoncée.
 * @param app Structure contenant les données de l'application.
 * @return Toujours 0 (convention pour les hooks MLX).
 */
int	keyboard_event(int keycode, t_app *app);

/**
 * @brief Gère les événements de la souris pour le zoom de la fractale.
 *
 * - Molette haut : Zoom avant (facteur 1.2).
 * - Molette bas : Zoom arrière (facteur 0.9).
 * - Ajuste également les offsets X et Y pour un zoom centré.
 * - Augmente le nombre d'itérations lorsque l'on zoome pour plus de détails.
 *
 * @param button Code du bouton de la souris pressé.
 * @param x Coordonnée X de la souris (non utilisé).
 * @param y Coordonnée Y de la souris (non utilisé).
 * @param app Structure contenant les données de l'application.
 * @return Toujours 0 (convention pour les hooks MLX).
 */
int	mouse_event(int button, int x, int y, t_app *app);

#endif
