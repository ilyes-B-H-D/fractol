/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:13:16 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 23:44:30 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_burningship(t_data *img, t_range range, t_colors *colors)
{
	int		x;
	int		y;
	int		iter;
	double	real;
	double	imag;
	
	x = 0;
	y = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			real = range.min_real + ((double)x / W) * (range.max_real
					- range.min_real);
			imag = range.max_imag + ((double)y / H) * -(range.max_imag
					- range.min_imag);
			iter = get_burningship_color(real, imag);
			my_mlx_pixel_put(img, x, y, ft_get_color(iter, colors));
			y++;
		}
		x++;
	}
}

int	get_burningship_color(double real, double imag)
{
	int		iter;
	double	z_real;
	double	z_imag;
	double	next_real;
	double	next_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < 100 && z_real * z_real + z_imag * z_imag < 4.0)
	{
		next_real = z_real * z_real - z_imag * z_imag + real;
		next_imag = -2.0 * fabs(z_real * z_imag) + imag;
		z_real = next_real;
		z_imag = next_imag;
		iter++;
	}
	return (iter);
}
