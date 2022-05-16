/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:56:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 17:17:00 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_init_values(t_vars *vars, int width, int height, int mode)
{
	int	limits[4];

	ft_get_limits(vars, (int *) limits);
	ft_update_matrix(vars, limits);
	vars->offset_x = (limits[1] - limits[0]) / 2
		+ (width - (limits[1] - limits[0])) / 2;
	vars->offset_y = (limits[3] - limits[2]) / 2
		+ (height - (limits[3] - limits[2])) / 2;
	vars->zoom = (float) width / ((limits[1] - limits[0]) + 100);
	if (vars->zoom > (float) height / ((limits[3] - limits[2]) + 100))
		vars->zoom = (float) height / ((limits[3] - limits[2]) + 100);
	vars->width = width;
	vars->height = height;
	vars->mouse_1 = 0;
	vars->mouse_2 = 0;
	vars->initial_x = 0;
	vars->initial_y = 0;
	vars->mode = mode;
}

void	ft_set_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, hook, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_hook(vars->win, 5, 1L << 3, ft_mouse, vars);
	mlx_hook(vars->win, 6, 1L << 6, ft_motion, vars);
	mlx_hook(vars->win, 4, 1L << 2, mouse_hook, vars);
}

t_vars	*ft_init_vars(char *path, int width, int height, int mode)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		ft_error("Memory");
	vars->matrix = ft_parse(vars, path);
	ft_init_values(vars, width, height, mode);
	if (mode == 1)
		ft_convert_sphere(vars->matrix);
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_free_to_null(vars->matrix);
		ft_error("Memory");
	}
	vars->win = mlx_new_window(vars->mlx, width, height, path);
	if (!vars->win)
	{
		ft_free_to_null(vars->matrix);
		mlx_destroy_display(vars->mlx);
		ft_error("Memory");
	}
	ft_set_hook(vars);
	return (vars);
}

void	ft_free_data(t_vars *vars)
{
	ft_free_to_null(vars->matrix);
	mlx_destroy_image(vars->mlx, vars->image);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
}
