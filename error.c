/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:18:39 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 17:20:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_free_double_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_error(char *msg)
{
	if (errno)
	{
		perror(msg);
		exit(errno);
	}
	else
	{
		ft_putstr_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_test_fd(t_vars *vars, int fd)
{
	if (fd == -1)
	{
		free(vars);
		ft_error("Path");
	}
}
