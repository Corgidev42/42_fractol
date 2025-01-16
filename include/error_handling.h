/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:38:04 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 10:54:21 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

/**
 * @brief Checks if the given string represents a valid double.
 *
 * This function takes a string as input and determines if it can be
 * interpreted as a double-precision floating-point number.
 *
 * @param str The string to be checked.
 * @return 1 if the string is a valid double, 0 otherwise.
 */
int	is_double(char *str);

/**

	* @brief Checks the validity of the command-line arguments and initializes the application.
 *

	* This function takes the command-line arguments and the application structure as input,

	* and performs necessary checks to ensure the arguments are valid. If the arguments are valid,
 * it initializes the application structure accordingly.
 *
 * @param argv The array of command-line arguments.
 * @param app A pointer to the application structure to be initialized.
 * @return An integer indicating the success or failure of the operation.

	*         Returns 1, 2 or 3 if the arguments are valid and the application is initialized successfully.
 *         Returns 0 if there is an error.
 */
int	check_entry(char *argv[], t_app *app);

#endif
