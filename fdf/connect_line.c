/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:35:27 by psanger           #+#    #+#             */
/*   Updated: 2024/01/17 17:55:59 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	connect_line_x(t_data *data)
{
	int		num_pixel;
	int		i;
	float	t_x;
	float	t_y;
	float	t_z;

	if (data->x > WIDTH - 1 || data->x < 0 || data->x1 > WIDTH - 1
		|| data->x1 < 0 || data->y > HEIGHT - 1 || data->y < 0
		|| data->y1 > HEIGHT - 1 || data->y1 < 0)
		return ;
	i = 0;
	num_pixel = ft_abs(data->x1 - data->x);
	if (ft_abs(data->x1 - data->x) < ft_abs(data->y1 - data->y))
		num_pixel = ft_abs(data->y1 - data->y);
	while (i < num_pixel)
	{
		t_z = (float)data->z + (float)i * ((float)data->z1 - (float)data->z)
			/ (float)num_pixel;
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

	if (data->x > WIDTH - 1 || data->x < 0 || data->x2 > WIDTH - 1
		|| data->x2 < 0 || data->y > HEIGHT - 1 || data->y < 0
		|| data->y2 > HEIGHT - 1 || data->y2 < 0)
		return ;
	i = 0;
	num_pixel = ft_abs(data->x2 - data->x);
	if (ft_abs(data->x2 - data->x) < ft_abs(data->y2 - data->y))
		num_pixel = ft_abs(data->y2 - data->y);
	while (i < num_pixel)
	{
		t_z = (float)data->z + (float)i * ((float)data->z2 - (float)data->z)
			/ (float)num_pixel;
		t_x = data->x + i * (data->x2 - data->x) / num_pixel;
		t_y = data->y + i * (data->y2 - data->y) / num_pixel;
		mlx_put_pixel(data->image, t_x, t_y, get_rgba_custom(t_z, data));
		i++;
	}
}
