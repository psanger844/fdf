/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:17:13 by psanger           #+#    #+#             */
/*   Updated: 2023/12/11 20:53:08 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(data->image, x, y, get_rgba(0, 0, 0, 255));
			x++;
		}
		x = 0;
		y++;
	}
}

void	test(t_data *data)
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

void	ft_hook2(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		free_matrix(data);
		mlx_terminate(data->mlx);
		free(data);
		system("leaks fdf");
		exit (0);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->rotation += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->rotation -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->rotation1 += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->rotation1 -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		data->distance += 2;
	if (mlx_is_key_down(data->mlx, MLX_KEY_M))
		data->distance -= 2;
	reset(data);
	test(data);
}

int	y_coordiante(int x, int y, t_data *data)
{
	float	len;
	float	y2;
	float	delta_x;
	float	delta_y;
	float	alpha;

	delta_x = (float)(x) - (float)((data->len_x) / 2);
	delta_y = (float)(y) - (float)((data->len_y) / 2);
	if (delta_x == 0 && y > data->len_y / 2)
		alpha = 270;
	if (delta_x == 0 && y <= data->len_y / 2)
		alpha = 90;
	if (x <= (float)(data->len_x / 2))
		alpha = atan(delta_y / delta_x) * (180 / PI) + 180;
	if (x >= (float)(data->len_x / 2))
		alpha = atan(delta_y / delta_x) * (180 / PI);
	len = data->distance * pow ((pow(delta_x, 2) + pow(delta_y, 2)), 0.5);
	if (len == 0)
		return (WIDTH / 2 - sin(data->rotation1 * PI / 180) * data->distance * data->matrix[y][x]);
	y2 = sin(((alpha + data->rotation) * PI) / 180) * len + HEIGHT / 2;
	y2 = HEIGHT / 2 + (y2 - HEIGHT / 2) * cos(data->rotation1 * PI / 180) - sin(data->rotation1 * PI / 180) * data->distance * data->matrix[y][x];
	return ((int)y2);
}

int	x_coordiante(int x, int y, t_data *data)
{
	float	len;
	float	x2;
	float	delta_x;
	float	delta_y;
	float	alpha;

	delta_x = (float)(x) - (float)((data->len_x) / 2);
	delta_y = (float)(y) - (float)((data->len_y) / 2);
	if (delta_x == 0 && y > data->len_y / 2)
		alpha = 270;
	if (delta_x == 0 && y <= data->len_y / 2)
		alpha = 90;
	if (x <= (float)(data->len_x / 2))
		alpha = atan(delta_y / delta_x) * (180 / PI) + 180;
	if (x >= (float)(data->len_x / 2))
		alpha = atan(delta_y / delta_x) * (180 / PI);
	len = data->distance * pow((pow(delta_x, 2) + pow(delta_y, 2)), 0.5);
	if (len == 0)
		return (WIDTH / 2);
	x2 = cos(((alpha + data->rotation) * PI) / 180) * len + WIDTH / 2;
	return ((int)x2);
}
