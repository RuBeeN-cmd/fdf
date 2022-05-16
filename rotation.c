/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:08:38 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/14 14:17:10 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_rotate_x(t_point *point, float theta)
{
	float	tmp;

	tmp = cos(theta) * point->y - sin(theta) * point->z;
	point->z = sin(theta) * point->y + cos(theta) * point->z;
	point->y = tmp;
}

void	ft_rotate_y(t_point *point, float theta)
{
	float	tmp;

	tmp = cos(theta) * point->x + sin(theta) * point->z;
	point->z = -sin(theta) * point->x + cos(theta) * point->z;
	point->x = tmp;
}

void	ft_rotate_z(t_point *point, float theta)
{
	float	tmp;

	tmp = cos(theta) * point->x - sin(theta) * point->y;
	point->y = sin(theta) * point->x + cos(theta) * point->y;
	point->x = tmp;
}

void	ft_rotate(t_vars *vars, float theta, void (*rotation)(t_point*, float))
{
	int		i;
	int		j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			rotation(vars->matrix[i][j], theta);
			j++;
		}
		i++;
	}
}
