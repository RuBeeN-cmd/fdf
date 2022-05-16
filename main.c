/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:48:27 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 14:27:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	int		mode;

	if (argc == 2)
		mode = 0;
	else if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "flat", ft_strlen("flat")))
			mode = 0;
		else if (!ft_strncmp(argv[2], "sphere", ft_strlen("sphere")))
			mode = 1;
		else
			ft_error("Usage: ./fdf file.fdf [flat | sphere]\n");
	}
	else
		ft_error("Usage: ./fdf file.fdf [flat | sphere]\n");
	vars = ft_init_vars(argv[1], 1920, 980, mode);
	ft_init_image(vars);
	ft_create_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image, 0, 0);
	mlx_loop(vars->mlx);
	ft_free_data(vars);
	return (EXIT_SUCCESS);
}
