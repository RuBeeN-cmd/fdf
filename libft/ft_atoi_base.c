/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:11:15 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 13:40:36 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_is_base_wrong(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	ft_where_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	coef;

	if (ft_is_base_wrong(base))
		return (0);
	coef = 1;
	nb = 0;
	while (*str == ' ' || (*str <= '\r' && *str >= '\t'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			coef = -coef;
			str++;
		}
		else
			str++;
	}
	while (ft_where_in_base(*str, base) != -1)
	{
		nb *= ft_strlen(base);
		nb += ft_where_in_base(*str++, base);
	}
	return (nb * coef);
}
