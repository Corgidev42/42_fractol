/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:34:22 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:11:36 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "fractol.h"

/**
 * @brief Affiche un message d'erreur,
	libère les ressources et quitte le programme.
 *
 *
	- Utilise `perror` pour afficher le message d'erreur
	avec des détails système.
 * - Appelle `kill_app` pour libérer la mémoire et fermer les fenêtres.
 * - Termine l'exécution avec `exit(EXIT_FAILURE)`.
 *
 * @param message Message d'erreur à afficher.
 * @param app Structure contenant les données de l'application.
 */
void	exit_error(const char *message, t_app *app);

/**
 * @brief Met à jour le rendu de la fractale en fonction du type sélectionné.
 *
 *
	- Détermine quel algorithme de fractale utiliser en fonction de `app->fractal_type`.
 * - Appelle la fonction `render_fractal` avec l'algorithme correspondant.
 *
	- Assure la mise à jour de l'affichage sans
	recalculer inutilement si l'état n'a pas changé.
 *
 * @param app Structure contenant les données de l'application.
 * @return Toujours 0 (convention pour les hooks MLX).
 */
int		update_frame(t_app *app);

#endif
