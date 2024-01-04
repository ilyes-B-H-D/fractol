/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:46:38 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 23:50:16 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(1, "\033[1;31mError: Invalid arguments\033[0m\n",
		sizeof("\033[1;31mError: Invalid arguments\033[0m\n"));
	write(1, "enter one of the following options :\n",
		sizeof("enter one of the following options :\n"));
	write(1, "* mandelbrot\n", sizeof("+ mandelbrot\n"));
	write(1, "* julia + imag + real\n", sizeof("+ julia + imag + real\n"));
	write(1, "* bonus\n", sizeof("+ bonus\n"));
}

int	close_red(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
}

void	ft_render(t_vars *data)
{
	t_colors	color;
	
	color.red = 10 + data->change_color;
	color.green = 9 + data->change_color;
	color.blue = 1 + data->change_color;
	if (data->fractol_name == 'm')
		ft_render_mandelbrot(&data->img, data->range, &color);
	else if (data->fractol_name == 'j')
		ft_render_julia(&data->img, data->range, data->av1, data->av2, &color);
	else if (data->fractol_name == 'b')
		ft_render_burningship(&data->img, data->range, &color);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
int	valid_double(char *str)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	else if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (dot > 1)
			return (0);
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}