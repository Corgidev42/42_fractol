/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:38:04 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/31 16:20:36 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "fractol.h"

int		is_double(char *str);
double	parse_fraction(char *str, int i);
double	ft_atod(char *str);
int		check_entry(char *argv[], t_app *app);

#endif
