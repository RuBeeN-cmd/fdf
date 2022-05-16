/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:53:51 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/12 13:48:28 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_read_file(int fd)
{
	char	c;
	char	*str;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	while (read(fd, &c, 1))
	{
		if (ft_str_add_char(&str, c) == -1)
		{
			free(str);
			return (NULL);
		}
	}
	return (str);
}
