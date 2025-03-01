/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:49:45 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 14:05:16 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_params(void)
{
	ft_printf("Usage: ./42_fractol [mandelbrot | julia | burning_ship]\n");
	ft_printf("for julia fractal, you can chose parameters re and im\n");
	ft_printf("Exemple: ./42_fractol mandelbrot\n");
	ft_printf("         ./42_fractol julia 0.101 0.956\n");
	ft_printf("........../42_fractol burning_ship\n");
}

int	main(int argc, char *argv[])
{
	t_app	app;
	int		fractal_type;

	if (argc >= 2)
	{
		init_app(&app);
		fractal_type = check_entry(argv, &app);
		if (fractal_type == 0)
		{
			print_params();
			return (-1);
		}
		app.fractal_type = fractal_type;
		fractal_app(&app);
	}
	else
		print_params();
	return (0);
}
