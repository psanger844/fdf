/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:17:13 by psanger           #+#    #+#             */
/*   Updated: 2023/12/12 17:55:24 by psanger          ###   ########.fr       */
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

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->move_y -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->move_y += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->move_x -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->move_x += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
		data->height += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->height -= 10;
	ft_hook2(data);
}

void	ft_hook2(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(data->mlx);
		free_matrix(data);
		free(data);
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
	parse_coordinates_1(data);
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
	data->temp = sin(data->rotation1 * PI / 180) * data->distance * data->matrix[y][x];
	if (len == 0)
		return (HEIGHT / 2 - data->temp + data->move_y);
	y2 = sin(((alpha + data->rotation) * PI) / 180) * len + HEIGHT / 2;
	y2 = HEIGHT / 2 + (y2 - HEIGHT / 2) * cos(data->rotation1 * PI / 180) - data->temp;
	if (data->matrix[y][x] != 0)
		y2 = y2 + data->height;
	return ((int)y2 + data->move_y);
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
		return (WIDTH / 2 + data->move_x);
	x2 = cos(((alpha + data->rotation) * PI) / 180) * len + WIDTH / 2;
	return ((int)x2 + data->move_x);
}
