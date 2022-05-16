/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:53:43 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/12 14:24:43 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_sub(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_chr(s, 0))
		len = 0;
	else if (start + len > ft_chr(s, 0))
		len = ft_chr(s, 0) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(ft_chr(s1, 0) + ft_chr(s2, 0) + 1);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	new_str[i] = 0;
	return (new_str);
}

int	ft_loop_read(int fd, t_dict_cell *cell)
{
	int		i;
	char	*str;

	str = malloc(BUFFER_SIZE + 1);
	cell->ret = read(fd, str, BUFFER_SIZE);
	if (cell->ret <= 0)
	{
		free(str);
		return (0);
	}
	str[cell->ret] = 0;
	cell->buf = ft_join_free(cell->buf, str);
	free(str);
	if (!cell->buf)
		return (0);
	i = 1;
	while (cell->ret && ft_chr(cell->buf, '\n') == -1)
	{
		if (!ft_read(str, cell, fd))
			return (0);
		i++;
	}
	return (1);
}

int	ft_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i - 1);
	if (c == 0)
		return (i);
	return (-1);
}

void	ft_del_fd(t_dict_cell *cell, t_dict_cell **list)
{
	t_dict_cell	*tmp_list;
	t_dict_cell	*bef_list;

	if ((*list)->fd != cell->fd)
	{
		bef_list = *list;
		tmp_list = (*list)->next;
		while (tmp_list && tmp_list->fd != cell->fd)
		{
			bef_list = tmp_list;
			tmp_list = tmp_list->next;
		}
		bef_list->next = tmp_list->next;
	}
	else
		*list = cell->next;
	free(cell);
}
