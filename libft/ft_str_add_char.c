/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:52:40 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/03 15:55:41 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_str_add_char(char **str, char c)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(*str) + 2));
	if (!new)
		return (-1);
	i = 0;
	while ((*str)[i])
	{
		new[i] = (*str)[i];
		i++;
	}
	new[i++] = c;
	new[i] = 0;
	free(*str);
	*str = new;
	return (0);
}
