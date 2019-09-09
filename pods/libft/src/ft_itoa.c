/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:57:36 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/12 21:21:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev(char *s, int i, int neg)
{
	char	*s1;
	int		y;

	i = ft_strlen(s);
	if (neg == 0)
		--i;
	s1 = (char *)malloc(sizeof(char) * i);
	y = 0;
	if (neg == 1)
		s1[y] = 45;
	while (s[y])
	{
		s1[i] = s[y];
		--i;
		++y;
	}
	if (neg == 1)
		++y;
	s1[y] = 0;
	free(s);
	return (s1);
}

static char		*ft_fusion(int i, int n, int neg)
{
	char *s;

	if (n == -2147483648)
		return (s = ft_strdup("-2147483648"));
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	if (n == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (neg == 1)
		n = -n;
	i = 0;
	while (n >= 10)
	{
		s[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (n > 0 && n < 10)
		s[i] = n + 48;
	s[++i] = 0;
	return (ft_rev(s, i, neg));
}

char			*ft_itoa(int nbr)
{
	int i;
	int n;
	int neg;

	neg = 0;
	i = 0;
	n = nbr;
	if (n < 0)
	{
		++i;
		n = -n;
		neg = 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (ft_fusion(i, nbr, neg));
}
