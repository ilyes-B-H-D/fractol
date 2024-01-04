/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:46:38 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 03:10:11 by iben-haj         ###   ########.fr       */
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
	if (data->fractol_name == 'm')
		ft_render_mandelbrot(&data->img, data->range);
	else if (data->fractol_name == 'j')
		ft_render_julia(&data->img, data->range, data->av1, data->av2);
	else if (data->fractol_name == 'b')
		ft_render_burningship(&data->img, data->range);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
