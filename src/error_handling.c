/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:37:42 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 12:31:23 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	divisor = 10.0;
	while (str[i])
	{
		fraction += (str[i] - '0') / divisor;
		divisor *= 10.0;
		i++;
	}
	return (sign * (result + fraction));
}

int	is_double(char *str)
{
	int	y;
	int	dot_count;
	y = 0;
	dot_count = 0;
	if (str[y] == '-' || str[y] == '+')
		y++;
	while (str[y])
	{
		if (str[y] == '.')
		{
			if (dot_count == 1)
			{
				ft_printf("Error\n");
				return (0);
			}
			dot_count++;
		}
		else if (!ft_isdigit(str[y]))
		{
			ft_printf("Error\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_entry(char *argv[], t_app *app)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
	if (ft_strncmp(argv[1], "julia", 5) == 0 && is_double(argv[2])
		&& is_double(argv[3]))
	{
		app->julia_re = ft_atod(argv[2]);
		app->julia_im = ft_atod(argv[3]);
		return (JULIA);
	}
	if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
		return (BURNING_SHIP);
	return (0);
}
