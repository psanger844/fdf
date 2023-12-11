/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:32:20 by psanger           #+#    #+#             */
/*   Updated: 2023/12/11 20:49:47 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

int	get_len_y_map(int fd)
{
	int		len_y;
	int		charsread;
	char	buffer;

	charsread = 1;
	len_y = 0;
	while (charsread > 0)
	{
		charsread = read(fd, &buffer, sizeof(char));
		if (charsread < 1)
			break ;
		if (buffer == '\n')
			len_y++;
	}
	return (len_y);
}

void	fill_matrix(int **matrix, char *line, int k, t_data *data)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_split(line, ' ');
	while (temp[i] != NULL)
		i++;
	data->len_x = i;
	matrix[k] = malloc(sizeof(int) * (i + 1));
	while (i > j)
	{
		matrix[k][j] = ft_atoi(temp[j]);
		j++;
	}
	matrix[k][j] = 0;
	ft_free(temp);
}

int	**get_matrix(int fd, int len_y, t_data *data)
{
	int		**matrix;
	int		i;
	char	*line;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * len_y);
	while (i < len_y)
	{
		line = get_next_line(fd);
		fill_matrix(matrix, line, i, data);
		i++;
		free (line);
		line = NULL;
	}
	return (matrix);
}
