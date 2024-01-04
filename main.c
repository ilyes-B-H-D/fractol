/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:03:28 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/04 23:19:08 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_vars *data, double zoom, double newx, double newy)
{
	data->range.min_real = (data->range.min_real - newx) * zoom + newx;
	data->range.max_real = (data->range.max_real - newx) * zoom + newx;
	data->range.min_imag = (data->range.min_imag - newy) * zoom + newy;
	data->range.max_imag = (data->range.max_imag - newy) * zoom + newy;
	ft_render(data);
}

int	mouse_scroll(int button, int x, int y, t_vars *data)
{
	double	zoom;
	double	newx;
	double	newy;

	zoom = 0.0;
	newx = data->range.min_real + ((double)x / W) * (data->range.max_real
			- data->range.min_real);
	newy = data->range.max_imag + ((double)y / H) * -(data->range.max_imag
			- data->range.min_imag);
	if (button == 4)
	{
		zoom = 1.1;
		data->zoomed /= 1.1;
		init(data, zoom, newx, newy);
	}
	else if (button == 5 && data->zoomed < 10000000000)
	{
		zoom = .9;
		data->zoomed *= 1.1;
		init(data, zoom, newx, newy);
	}
	return (0);
}

void	helper(t_vars *data, char **av)
{
	t_colors	color;
	
	color.red = 10;
	color.green = 9;
	color.blue = 1;
	if (!ft_strcmp(av[1], "mandelbrot"))
	{ 
		data->fractol_name = 'm';
		ft_render_mandelbrot(&data->img, data->range, &color);
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		data->fractol_name = 'j';
		ft_render_julia(&data->img, data->range, ft_atod(av[2]),
			ft_atod(av[3]), &color);
		data->av1 = ft_atod(av[2]);
		data->av2 = ft_atod(av[3]);
	}
	else if (!ft_strcmp(av[1], "bonus"))
	{
		data->fractol_name = 'b';
		ft_render_burningship(&data->img, data->range, &color);
	}
}

void	process_data(t_vars *data, char **av)
{
	mlx_hook(data->win, 17, 17L << 0, close_red, data);
	data->img.img = mlx_new_image(data->mlx, W, H);
	if (!data->img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		exit(0);
	}
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->range.min_real = -2.0;
	data->range.max_real = 2.0;
	data->range.min_imag = -2.0;
	data->range.max_imag = 2.0;
	data->zoomed = 1;
	helper(data, av);
	mlx_mouse_hook(data->win, mouse_scroll, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_vars	data;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 2
			&& !ft_strcmp(av[1], "bonus")) || (ac == 4 && !ft_strcmp(av[1],
				"julia") && valid_double(av[2]) && valid_double(av[3])))
	{
		data.mlx = mlx_init();
		if (!data.mlx)
			exit(0);
		data.change_color = 0;
		data.win = mlx_new_window(data.mlx, W, H, "mandelbrot");
		if (!data.win)
		{
			perror("Error\n");
			free(data.mlx);
			exit(0);
		}
		data.mlx = data.mlx;
		data.win = data.win;
		mlx_hook(data.win, 2, 1L << 0, close_r, &data);
		process_data(&data, av);
	}
	else
		error();
}
