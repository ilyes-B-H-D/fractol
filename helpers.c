/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:13:51 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/05 00:27:02 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_get_color(int iter, t_colors *colors)
{
	int	color;
	int	red;
	int	green;
	int	blue;
	
	red = iter * colors->red % 256;
	green = iter * colors->green % 256;
	blue = iter * colors->blue % 256;	
	if (iter == 100)
		color = 0;
	else
		color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*c;

	c = img->addr + (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)c = color;
}

void	arrows(int keycode, t_vars *vars)
{
	if (keycode == 123)
	{
		vars->range.min_real += (1 / (2 * vars->zoomed));
		vars->range.max_real += (1 / (2 * vars->zoomed));
	}
	else if (keycode == 124)
	{
		vars->range.min_real -= (1 / (2 * vars->zoomed));
		vars->range.max_real -= (1 / (2 * vars->zoomed));
	}
	else if (keycode == 125)
	{
		vars->range.min_imag += (1 / (2 * vars->zoomed));
		vars->range.max_imag += (1 / (2 * vars->zoomed));
	}
	else if (keycode == 126)
	{
		vars->range.min_imag -= (1 / (2 * vars->zoomed));
		vars->range.max_imag -= (1 / (2 * vars->zoomed));
	}
}

void	ft_change_color(int keycode, t_vars *vars)
{
	if (keycode == 8)
	{
		vars->change_color++;
		ft_render(vars);
	}
	
}

int	close_r(int keycode, t_vars *vars)
{
	arrows(keycode, vars);
	if (keycode == 53 || keycode == 17)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	ft_change_color(keycode, vars);
	ft_render(vars);
	return (0);
}
