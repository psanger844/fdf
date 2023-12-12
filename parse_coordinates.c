/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:15:42 by psanger           #+#    #+#             */
/*   Updated: 2023/12/12 13:16:37 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_coordinates_1(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->len_y - 1)
	{
		while (x < data->len_x)
		{
			data->x = x_coordiante(x, y, data);
			data->y = y_coordiante(x, y, data);
			data->z = data->matrix[y][x];
			data->x2 = x_coordiante(x, y + 1, data);
			data->y2 = y_coordiante(x, y + 1, data);
			data->z2 = data->matrix[y + 1][x];
			connect_line_y(data);
			x++;
		}
		x = 0;
		y++;
	}
	parse_coordinates_2(data);
}

void	parse_coordinates_2(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->len_y)
	{
		while (x < data->len_x - 1)
		{
			data->x = x_coordiante(x, y, data);
			data->y = y_coordiante(x, y, data);
			data->z = data->matrix[y][x];
			data->x1 = x_coordiante(x + 1, y, data);
			data->y1 = y_coordiante(x + 1, y, data);
			data->z1 = data->matrix[y][x + 1];
			connect_line_x(data);
			x++;
		}
		x = 0;
		y++;
	}
}
