/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:38:04 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/12 18:07:11 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "fractol.h"

/**
 * @brief Convertit la partie fractionnaire d'une chaîne en un nombre flottant.
 *
 * @param str La chaîne contenant le nombre.
 * @param i L'index où commence la partie fractionnaire.
 * @return La valeur de la partie fractionnaire sous forme de double.
 */
double	parse_fraction(char *str, int i);

/**
 * @brief Convertit une chaîne de caractères en un nombre flottant (double).
 *
 * @param str La chaîne à convertir.
 * @return Le nombre converti sous forme de double.
 */
double	ft_atod(char *str);

/**
 * @brief Affiche un message d'erreur et retourne 0.
 *
 * @return Toujours 0, indiquant une erreur.
 */
int		error_double(void);

/**
 * @brief Vérifie si une chaîne représente un nombre flottant valide.
 *
 * @param str La chaîne à vérifier.
 * @return 1 si c'est un nombre valide, 0 sinon.
 */
int		is_double(char *str);

/**
* @brief Vérifie les arguments d'entrée et initialise les paramètres nécessaires.
 *
 * @param argv Tableau contenant les arguments du programme.
 * @param app Structure contenant les données de l'application.
 * @return Un identifiant du type de fractale choisi, ou 0 en cas d'erreur.
 */
int		check_entry(char *argv[], t_app *app);

#endif
