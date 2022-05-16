/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:40:24 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/13 15:22:02 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	**ft_tabadd_row(void **tab)
{
	int		len;
	void	**new;

	len = ft_tablen((const void **) tab);
	new = malloc(sizeof(void **) * (len + 2));
	if (!new)
		return (NULL);
	new[len + 1] = NULL;
	new[len] = NULL;
	while (--len >= 0)
		new[len] = tab[len];
	free(tab);
	tab = new;
	return (tab);
}
