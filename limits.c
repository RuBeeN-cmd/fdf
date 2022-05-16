/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:57:27 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/09 18:24:19 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_check_limits(t_point *point, int *limits)
{
	if (point->x < limits[0])
		limits[0] = point->x;
	if (point->x > limits[1])
		limits[1] = point->x;
	if (point->y < limits[2])
		limits[2] = point->y;
	if (point->y > limits[3])
		limits[3] = point->y;
}

void	ft_get_limits(t_vars *vars, int *limits)
{
	int	i;
	int	j;

	limits[0] = vars->matrix[0][0]->x;
	limits[1] = vars->matrix[0][0]->x;
	limits[2] = vars->matrix[0][0]->y;
	limits[3] = vars->matrix[0][0]->y;
	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		if (!i)
			j++;
		while (vars->matrix[i][j])
		{
			ft_check_limits(vars->matrix[i][j], limits);
			j++;
		}
		i++;
	}
}

void	ft_update_matrix(t_vars *vars, int *limits)
{
	int	i;
	int	j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			vars->matrix[i][j]->x -= (limits[1] - limits[0]) / 2;
			vars->matrix[i][j]->y -= (limits[3] - limits[2]) / 2;
			j++;
		}
		i++;
	}
}
