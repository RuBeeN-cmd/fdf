/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:43:29 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 17:19:16 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_free_to_null(t_point ***matrix)
{
	int	i;
	int	j;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
		{
			j = 0;
			while (matrix[i][j])
			{
				free(matrix[i][j]);
				j++;
			}
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

int	ft_hex_to_int(char *nb)
{
	int	i;

	i = 'A';
	while (i <= 'F')
	{
		if (ft_strchr(nb, i++))
			return (ft_atoi_base(nb, "0123456789ABCDEF"));
	}
	return (ft_atoi_base(nb, "0123456789abcdef"));
}

void	ft_parse_cell(t_point ***matrix, char *cell, int i, int j)
{
	char	**numbers;

	numbers = ft_split(cell, ',');
	matrix[i][j] = malloc(sizeof(t_point));
	matrix[i][j]->x = j * 50;
	matrix[i][j]->y = i * 50;
	matrix[i][j]->z = ft_atoi(numbers[0]) * 50;
	matrix[i][j]->color = 0xFFFFFFFF;
	if (numbers[1])
		matrix[i][j]->color = ft_hex_to_int(numbers[1] + 2) + (0xFF << 24);
	ft_free_double_tab((void **) numbers);
}

void	ft_parse_line(t_point ****matrix, char *line, int i)
{
	char	**cells;
	int		line_len;
	int		j;

	cells = ft_split(line, ' ');
	*matrix = (t_point ***) ft_tabadd_row((void **) *matrix);
	line_len = ft_tablen((const void **) cells);
	(*matrix)[i] = malloc(sizeof(t_point *) * (line_len + 1));
	(*matrix)[i][line_len] = NULL;
	j = 0;
	while (cells[j])
	{
		ft_parse_cell(*matrix, cells[j], i, j);
		j++;
	}
	ft_free_double_tab((void **) cells);
}

t_point	***ft_parse(t_vars *vars, char *path)
{
	int		fd;
	t_point	***matrix;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	ft_test_fd(vars, fd);
	matrix = malloc(sizeof(t_point **) * 1);
	matrix[0] = NULL;
	i = 0;
	line = get_next_line(fd);
	if (line[ft_strlen((const char *) line) - 1] == '\n')
		line[ft_strlen((const char *) line) - 1] = 0;
	while (line)
	{
		ft_parse_line(&matrix, line, i);
		free(line);
		line = get_next_line(fd);
		if (line && line[ft_strlen((const char *) line) - 1] == '\n')
			line[ft_strlen((const char *) line) - 1] = 0;
		i++;
	}
	close(fd);
	return (matrix);
}
