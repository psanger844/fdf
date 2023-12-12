/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:18:19 by psanger           #+#    #+#             */
/*   Updated: 2023/12/12 17:14:21 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_biggest(t_data *data)
{
	int	i;
	int	j;
	int	biggest;

	i = 0;
	j = 0;
	biggest = data->matrix[i][j] + data->height;
	while (i < data->len_y)
	{
		while (j < data->len_x)
		{
			if (biggest < data->matrix[i][j] + data->height)
				biggest = data->matrix[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (biggest);
}

int	get_rgba_custom(float value, t_data *data)
{
	int		r;
	float	g;
	float	b;
	int		a;
	int		biggest;

	biggest = get_biggest(data);
	value = ft_abs(value);
	biggest = ft_abs(biggest);
	r = 255;
	g = 255 - ((float)value / (float)biggest * 255);
	b = 255 - ((float)value / (float)biggest * 255);
	a = 255;
	return (r << 24 | (int)g << 16 | (int)b << 8 | a);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
