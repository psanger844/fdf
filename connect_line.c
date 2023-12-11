/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:35:27 by psanger           #+#    #+#             */
/*   Updated: 2023/12/11 19:28:25 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_line_x(t_data *data)
{
	int		num_pixel;
	int		i;
	float	t_x;
	float	t_y;
	float	t_z;

	if (data->x > WIDTH || data->x < 0 || data->x1 > WIDTH || data->x1 < 0
		|| data->y > HEIGHT || data->y < 0 || data->y1 > HEIGHT || data->y1 < 0)
		return ;
	i = 0;
	num_pixel = abs(data->x1 - data->x);
	if (abs(data->x1 - data->x) < abs(data->y1 - data->y))
		num_pixel = abs(data->y1 - data->y);
	while (i < num_pixel)
	{
		t_z = data->z + i * (data->z1 - data->z) / num_pixel;
		t_x = data->x + i * (data->x1 - data->x) / num_pixel;
		t_y = data->y + i * (data->y1 - data->y) / num_pixel;
		mlx_put_pixel(data->image, t_x, t_y, get_rgba_custom(t_z, data));
		i++;
	}
}

void	connect_line_y(t_data *data)
{
	int		num_pixel;
	int		i;
	float	t_x;
	float	t_y;
	float	t_z;

	if (data->x > WIDTH || data->x < 0 || data->x2 > WIDTH || data->x2 < 0
		|| data->y > HEIGHT || data->y < 0 || data->y2 > HEIGHT || data->y2 < 0)
		return ;
	i = 0;
	num_pixel = abs(data->x2 - data->x);
	if (abs(data->x2 - data->x) < abs(data->y2 - data->y))
		num_pixel = abs(data->y2 - data->y);
	while (i < num_pixel)
	{
		t_z = data->z + i * (data->z2 - data->z) / num_pixel;
		t_x = data->x + i * (data->x2 - data->x) / num_pixel;
		t_y = data->y + i * (data->y2 - data->y) / num_pixel;
		mlx_put_pixel(data->image, t_x, t_y, get_rgba_custom(t_z, data));
		i++;
	}
}
