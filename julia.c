/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:13:59 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 01:28:09 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia_color(double real, double imag, double ac1, double ac2)
{
	int		iter;
	double	next_real;
	double	next_imag;

	iter = 0;
	while (iter < 100 && real * real + imag * imag < 4.0)
	{
		next_real = real * real - imag * imag + ac1;
		next_imag = 2.0 * real * imag + ac2;
		real = next_real;
		imag = next_imag;
		iter++;
	}
	return (iter);
}

void	ft_render_julia(t_data *img, t_range range, double ac1, double ac2)
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
			iter = get_julia_color(real, imag, ac1, ac2);
			my_mlx_pixel_put(img, x, y, ft_get_color(iter));
			y++;
		}
		x++;
	}
}
