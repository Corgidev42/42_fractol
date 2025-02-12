/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:09:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATION_H
# define ITERATION_H

# include "fractol.h"

/**

	* @brief Calcule le nombre d'itérations pour un point donné dans l'ensemble Burning Ship.
 *
 *
	- L'algorithme applique une transformation spécifique en prenant la valeur absolue des coordonnées.
 *
	- La boucle s'arrête lorsque |Z| dépasse 2 ou que le nombre maximal d'itérations est atteint.
 *
 * @param real Partie réelle du point initial.
 * @param imag Partie imaginaire du point initial.
 * @param app Structure contenant les paramètres de l'application,
	y compris max_iter.
 * @return Le nombre d'itérations effectuées avant divergence.
 */
int	burning_ship_iterations(double real, double imag, t_app *app);

/**

	* @brief Calcule le nombre d'itérations pour un point donné dans l'ensemble Julia.
 *
 *
	- Chaque point évolue selon une fonction quadratique avec un paramètre complexe fixe.
 *
	- La boucle s'arrête lorsque |Z| dépasse 2 ou que le nombre maximal d'itérations est atteint.
 *
 * @param z_re Partie réelle du point initial.
 * @param z_im Partie imaginaire du point initial.
 * @param app Structure contenant les paramètres de l'application,
	y compris les constantes de Julia.
 * @return Le nombre d'itérations effectuées avant divergence.
 */
int	julia_iterations(double z_re, double z_im, t_app *app);

/**

	* @brief Calcule le nombre d'itérations pour un point donné dans l'ensemble Mandelbrot.
 *
 *
	- Chaque point évolue selon une fonction quadratique avec des valeurs initiales spécifiques.
 *
	- La boucle s'arrête lorsque |Z| dépasse 2 ou que le nombre maximal d'itérations est atteint.
 *
 * @param real Partie réelle du point initial.
 * @param imag Partie imaginaire du point initial.
 * @param app Structure contenant les paramètres de l'application,
	y compris max_iter.
 * @return Le nombre d'itérations effectuées avant divergence.
 */
int	mandelbrot_iterations(double real, double imag, t_app *app);

#endif
