/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:01:44 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/20 17:42:25 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 1;
	if (c == '\0')
		return (ft_strlen(s) + (char *)s);
	while (s[i] && cmp == 1)
	{
		if (s[i] == c)
			--cmp;
		++i;
	}
	if (cmp == 1)
		return (0);
	i = i - 1;
	return ((char *)&s[i]);
}
