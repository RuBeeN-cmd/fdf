/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:46:50 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 16:29:15 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_update_points(t_vars *vars, t_point *point1, t_point *point2)
{
	point1->x = (int)(point1->x * vars->zoom + vars->offset_x);
	point1->y = (int)(point1->y * vars->zoom + vars->offset_y);
	point2->x = (int)(point2->x * vars->zoom + vars->offset_x);
	point2->y = (int)(point2->y * vars->zoom + vars->offset_y);
}

int	ft_segment_is_visible(t_vars *vars, t_point point1, t_point point2)
{
	return (!(point1.x < vars->width && point1.y < vars->height
			&& point1.x >= 0 && point1.y >= 0)
		&& !(point2.x < vars->width && point2.y < vars->height
			&& point2.x >= 0 && point2.y >= 0));
}

void	ft_draw_segment(t_vars *vars, t_point point1, t_point point2)
{
	int		dx;
	int		dy;

	ft_update_points(vars, &point1, &point2);
	if (ft_segment_is_visible(vars, point1, point2))
		return ;
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (abs(dx) > abs(dy))
		ft_segment_dx(vars, point1, point2);
	else
		ft_segment_dy(vars, point1, point2);
}

int	ft_get_color(t_point *a, t_point *b, int step, int total_step)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	if (!total_step)
		total_step = 1;
	while (i <= 3)
	{
		color += (int)(((a->color >> (i * 8)) & 0xFF)
				+ ((((b->color >> (i * 8)) & 0xFF)
						- ((a->color >> (i * 8)) & 0xFF))
					* step / (float) total_step))
			<< (i * 8);
		i++;
	}
	return (color);
}

void	ft_swap_point(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
