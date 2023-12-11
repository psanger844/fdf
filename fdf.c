/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:03:48 by psanger           #+#    #+#             */
/*   Updated: 2023/12/11 20:52:16 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (data->matrix[i])
		i++;
	while (i)
	{
		free(data->matrix[i]);
		i--;
	}
	free(data->matrix);
}

void	init(t_data *data)
{
	data->rotation = 45;
	data->rotation1 = 45;
	data->distance = 10;
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->big = 1;
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	mlx_loop_hook(data->mlx, ft_hook2, data);
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
	data->len_y = get_len_y_map(fd);
	fd = open(argv[1], O_RDONLY);
	data->matrix = get_matrix(fd, data->len_y, data);
	close (fd);
	init(data);
	free_matrix(data);
	free(data);
	return (0);
}
