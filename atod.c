/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:13:23 by iben-haj          #+#    #+#             */
/*   Updated: 2024/01/02 19:58:17 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"
#include <stdio.h>

int	ft_helper(char *str, int *sign, int *digits, int i)
{
	if (str[i++] == '-')
		*sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		*digits = (str[i++] - '0') + (*digits * 10);
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	int		digits;
	double	floating;
	double	f;

	f = 0.1;
	floating = 0.0;
	i = 0;
	digits = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	i = ft_helper(str, &sign, &digits, i);
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			floating += (str[i++] - '0') * f;
			f /= 10;
		}
	}
	return (sign * (digits + floating));
}
