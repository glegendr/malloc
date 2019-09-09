/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:01:44 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/23 12:54:19 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 1;
	while (s[i])
		++i;
	if (c == '\0')
		return ((char *)&s[i]);
	i = i - 1;
	while (i >= 0 && s[i] && cmp == 1)
	{
		if (s[i] == c)
			--cmp;
		--i;
	}
	if (cmp == 1)
		return (0);
	i = i + 1;
	return ((char *)&s[i]);
}
