/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:03:48 by psanger           #+#    #+#             */
/*   Updated: 2023/12/12 17:02:46 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->rotation = 0;
	data->rotation1 = 0;
	data->distance = 10;
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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	data->len_y = get_len_y_map(fd);
	fd = open(argv[1], O_RDONLY);
	data->matrix = get_matrix(fd, data->len_y, data);
	close (fd);
	init(data);
	free_matrix(data);
	free(data);
	return (0);
}
