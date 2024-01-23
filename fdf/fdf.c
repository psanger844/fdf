/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:03:48 by psanger           #+#    #+#             */
/*   Updated: 2024/01/22 19:11:29 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mid_exit(t_data *data)
{
	if (data->matrix)
		free(data->matrix);
	if (!data)
		free(data);
	exit(1);
}

void	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_y)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	init(t_data *data)
{
	data->rotation = 45;
	data->r1 = 45;
	data->distance = 10;
	if (data->len_x > 100)
		data->distance = 1;
	data->move_x = 0;
	data->move_y = 0;
	data->height = 0;
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_mid_exit(data);
	data->len_y = get_len_y_map(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_mid_exit(data);
	data->matrix = get_matrix(fd, data->len_y, data);
	close(fd);
	init(data);
	free_matrix(data);
	free(data);
	return (0);
}
