/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:21:10 by psanger           #+#    #+#             */
/*   Updated: 2024/01/22 19:10:19 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "LIBFT/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define PI 3.14159265358979323846

typedef struct s_data
{
	float		rotation;
	float		r1;
	int			**matrix;
	int			len_y;
	int			len_x;
	int			distance;
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			x;
	int			y;
	int			z;
	int			x1;
	int			y1;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
	float		temp;
	int			move_x;
	int			move_y;
	int			height;
}				t_data;

void			ft_mid_exit(t_data *data);

int				**get_matrix(int fd, int len_y, t_data *data);
int				get_len_y_map(int fd);
void			fill_matrix(int **matrix, char *line, int k, t_data *data);

void			ft_hook(void *param);
void			ft_hook2(void *param);

int				y_coordiante(int x, int y, t_data *data);
int				x_coordiante(int x, int y, t_data *data);

void			print_point(t_data *data, int x, int y);
void			reset_point(t_data *data, int x, int y);
void			reset(t_data *data);

int				get_rgba_custom(float value, t_data *data);
int				get_rgba(int r, int g, int b, int a);

void			connect_line_x(t_data *data);
void			connect_line_y(t_data *data);
int				ft_abs(int num);

void			parse_coordinates_1(t_data *data);
void			parse_coordinates_2(t_data *data);
void			free_matrix(t_data *data);

#endif
