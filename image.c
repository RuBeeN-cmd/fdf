/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:15:03 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 16:00:04 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_init_image(t_vars *vars)
{
	vars->image = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->buffer = mlx_get_data_addr(vars->image,
			&(vars->pixel_bits), &(vars->line_bytes), &(vars->endian));
}

void	ft_pixel_put(t_vars *vars, int x, int y, int color)
{
	int	pixel;

	if (x < vars->width && y < vars->height && x >= 0 && y >= 0)
	{
		if (vars->pixel_bits != 32)
			color = mlx_get_color_value(vars->mlx, color);
		pixel = y * vars->line_bytes + x * 4;
		vars->buffer[pixel + vars->endian * 3] = (color) & 0xFF;
		vars->buffer[pixel + vars->endian + 1] = (color >> 8) & 0xFF;
		vars->buffer[pixel + !vars->endian + 1] = (color >> 16) & 0xFF;
		vars->buffer[pixel + !vars->endian * 3] = (color >> 24) & 0xFF;
	}
}

void	ft_create_image(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			if (j > 0)
				ft_draw_segment(vars, *(vars->matrix[i][j - 1]),
					*(vars->matrix[i][j]));
			if (i > 0)
				ft_draw_segment(vars, *(vars->matrix[i - 1][j]),
					*(vars->matrix[i][j]));
			j++;
		}
		i++;
	}
}

void	ft_get_new_frame(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image);
	ft_init_image(vars);
	ft_create_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image, 0, 0);
}
