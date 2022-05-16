/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:53:57 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/12 14:24:52 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_dict_cell	*ft_new_fd(int fd)
{
	t_dict_cell	*list;

	list = (t_dict_cell *) malloc(sizeof(t_dict_cell));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->fd = fd;
	list->buf = malloc(1);
	list->buf[0] = 0;
	list->ret = BUFFER_SIZE;
	return (list);
}

t_dict_cell	*ft_lstget_cell(int fd, t_dict_cell **list)
{
	t_dict_cell	*cell;

	if (!(*list))
	{
		*list = ft_new_fd(fd);
		if (!(*list))
			return (NULL);
		return (*list);
	}
	cell = *list;
	while (cell->next && cell->fd != fd)
		cell = cell->next;
	if (!cell->next && cell->fd != fd)
	{
		cell->next = ft_new_fd(fd);
		if (!cell->next)
			return (NULL);
		cell = cell->next;
	}
	return (cell);
}

int	ft_read(char *str, t_dict_cell *cell, int fd)
{
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	cell->ret = read(fd, str, BUFFER_SIZE);
	str[cell->ret] = 0;
	cell->buf = ft_join_free(cell->buf, str);
	free(str);
	if (!cell->buf)
		return (0);
	return (1);
}

char	*ft_start_read(int fd, t_dict_cell **list, t_dict_cell **c)
{
	char	*str;
	char	*n;

	if (!ft_loop_read(fd, (*c)))
	{
		str = NULL;
		if ((*c)->buf[0])
			str = (*c)->buf;
		else
			free((*c)->buf);
		ft_del_fd(*c, list);
		return (str);
	}
	else if (ft_chr((*c)->buf, '\n') >= 0)
	{
		str = ft_sub((*c)->buf, 0, ft_chr((*c)->buf, '\n') + 1);
		n = ft_sub((*c)->buf, ft_chr((*c)->buf, 10) + 1, ft_chr((*c)->buf, 0));
		free((*c)->buf);
		(*c)->buf = n;
		return (str);
	}
	str = (*c)->buf;
	ft_del_fd(*c, list);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_dict_cell	*list;
	t_dict_cell			*tp;
	char				*str;
	char				*new;

	tp = ft_lstget_cell(fd, &list);
	if (ft_chr(tp->buf, '\n') >= 0)
	{
		str = ft_sub(tp->buf, 0, ft_chr(tp->buf, '\n') + 1);
		new = ft_sub(tp->buf, ft_chr(tp->buf, 10) + 1, ft_chr(tp->buf, 0));
		free(tp->buf);
		tp->buf = new;
	}
	else if (tp->ret < BUFFER_SIZE)
	{
		str = tp->buf;
		ft_del_fd(tp, &list);
		if (str[0])
			return (str);
		free(str);
		return (NULL);
	}
	else
		str = ft_start_read(fd, &list, &tp);
	return (str);
}
