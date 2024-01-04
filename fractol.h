/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:13:47 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 23:25:53 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define W 700
# define H 700

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex_range
{
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
}			t_range;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	fractol_name;
	double	av1;
	double	av2;
	double	zoomed;
	int		change_color;
	t_data	img;
	t_range	range;
}			t_vars;

typedef struct colors
{
	int	red;
	int	green;
	int	blue;
}			t_colors;

int			ft_strcmp(const char *s1, const char *s2);
int			close_r(int keycode, t_vars *vars);

int			ft_get_color(int iter, t_colors *colors);
void		ft_render(t_vars *data);
void		ft_render_mandelbrot(t_data *img, t_range range, t_colors *colors);
void		ft_render_julia(t_data *img, t_range range, double ac1, double ac2, t_colors *colors);
void		ft_render_burningship(t_data *img, t_range range, t_colors *colors);

void		my_mlx_pixel_put(t_data *img, int x, int y, int color);

int			get_mandelbrot_color(double real, double imag);
int			get_julia_color(double real, double imag, double ac1, double ac2);
int			get_burningship_color(double real, double imag);

int			close_r(int keycode, t_vars *vars);
int			close_red(t_vars *vars);

double		ft_atod(char *str);
void		change_color(int keycode, t_vars *vars);
int			valid_double(char *str);
void		error(void);
#endif