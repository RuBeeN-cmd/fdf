/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:56:34 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 15:40:39 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_convert_sphere(t_point ***matrix)
{
	int		i;
	int		j;
	int		row;
	float	theta;
	float	theta_x;

	row = ft_tablen((const void **) matrix);
	theta = 2 * PI / (ft_tablen((const void **) matrix[0]) - 1);
	theta_x = PI / (row - 1);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			matrix[i][j]->x = 0;
			matrix[i][j]->y = 0;
			matrix[i][j]->z += row * 50 / 2;
			ft_rotate_x(matrix[i][j], theta_x * (i - ((float)(row - 1) / 2)));
			ft_rotate_y(matrix[i][j], theta * j);
			j++;
		}
		i++;
	}
}
