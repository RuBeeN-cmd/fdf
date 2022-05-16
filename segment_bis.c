/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:25:37 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 16:27:55 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_segment_dx(t_vars *vars, t_point point1, t_point point2)
{
	int		dx;
	int		dy;
	float	e;
	int		color;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (dx < 0)
	{
		ft_swap_point(&point1, &point2);
		dx *= -1;
		dy *= -1;
	}
	e = (float) dy / (float) dx;
	while (point1.x <= point2.x)
	{
		color = ft_get_color(&point1, &point2, point1.x - point2.x + dx, dx);
		ft_pixel_put(vars, point1.x, (int) point1.y, color);
		point1.x++;
		point1.y += e;
	}
}

void	ft_segment_dy(t_vars *vars, t_point point1, t_point point2)
{
	int		dx;
	int		dy;
	float	e;
	int		color;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (dy < 0)
	{
		ft_swap_point(&point1, &point2);
		dx *= -1;
		dy *= -1;
	}
	e = (float) dx / (float) dy;
	while (point1.y <= point2.y)
	{
		color = ft_get_color(&point1, &point2, point1.y - point2.y + dy, dy);
		ft_pixel_put(vars, (int) point1.x, point1.y, color);
		point1.y++;
		point1.x += e;
	}
}
