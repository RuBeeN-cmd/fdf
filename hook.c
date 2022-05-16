/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:41:57 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/14 18:50:40 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_motion(int x, int y, t_vars *vars)
{
	if (vars->mouse_1)
	{
		vars->offset_x += x - vars->initial_x;
		vars->offset_y += y - vars->initial_y;
		vars->initial_x = x;
		vars->initial_y = y;
		ft_get_new_frame(vars);
	}
	else if (vars->mouse_2)
	{
		ft_rotate(vars, (PI / 24) * 0.05 * (x - vars->initial_x), ft_rotate_y);
		ft_rotate(vars, -(PI / 24) * 0.05 * (y - vars->initial_y), ft_rotate_x);
		vars->initial_x = x;
		vars->initial_y = y;
		ft_get_new_frame(vars);
	}
	return (0);
}

int	ft_mouse(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		if (!vars->mouse_1)
		{
			vars->initial_x = x;
			vars->initial_y = y;
		}
		vars->mouse_1 = !vars->mouse_1;
	}
	else if (button == 3)
	{
		if (!vars->mouse_2)
		{
			vars->initial_x = x;
			vars->initial_y = y;
		}
		vars->mouse_2 = !vars->mouse_2;
	}
	return (0);
}

int	ft_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
		{
			vars->offset_x -= 0.1 * (x - vars->offset_x);
			vars->offset_y -= 0.1 * (y - vars->offset_y);
			vars->zoom *= 1.1;
		}
		else
		{
			vars->offset_x += 0.1 * (vars->width / 2 - vars->offset_x);
			vars->offset_y += 0.1 * (vars->height / 2 - vars->offset_y);
			vars->zoom *= 0.9;
		}
		ft_get_new_frame(vars);
	}
	else if (button == 1 || button == 3)
		ft_mouse(button, x, y, vars);
	return (0);
}
