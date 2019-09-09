/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:37:35 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/12 21:21:28 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *s)
{
	int i;
	int nb;
	int pos;
	int cmp;

	cmp = 0;
	pos = 1;
	i = 0;
	nb = 0;
	while (ft_isspace(s[i]) == 1)
		++i;
	if ((s[i] == 45 || s[i] == 43) && ft_isdigit(s[i + 1]) == 1)
	{
		if (s[i] == 45)
			pos = 0;
		++i;
	}
	else if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]) && ++cmp != -42)
		nb = (nb * 10) - (s[i++] - 48);
	if (pos == 1)
		nb = -nb;
	return (nb);
}

long int			ft_atoli(const char *s)
{
	long int i;
	long int nb;
	long int pos;
	long int cmp;

	cmp = 0;
	pos = 1;
	i = 0;
	nb = 0;
	while (ft_isspace(s[i]) == 1)
		++i;
	if ((s[i] == 45 || s[i] == 43) && ft_isdigit(s[i + 1]) == 1)
	{
		if (s[i] == 45)
			pos = 0;
		++i;
	}
	else if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]) && ++cmp != -42)
		nb = (nb * 10) - (s[i++] - 48);
	if (pos == 1)
		nb = -nb;
	return (nb);
}

long long int		ft_atolli(const char *s)
{
	long long int i;
	long long int nb;
	long long int pos;
	long long int cmp;

	cmp = 0;
	pos = 1;
	i = 0;
	nb = 0;
	while (ft_isspace(s[i]) == 1)
		++i;
	if ((s[i] == 45 || s[i] == 43) && ft_isdigit(s[i + 1]) == 1)
	{
		if (s[i] == 45)
			pos = 0;
		++i;
	}
	else if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]) && ++cmp != -42)
		nb = (nb * 10) - (s[i++] - 48);
	if (pos == 1)
		nb = -nb;
	return (nb);
}
