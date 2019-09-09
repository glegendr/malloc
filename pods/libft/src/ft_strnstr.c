/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:13:03 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/20 17:41:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_check(const char *str1, const char *str2)
{
	if (str1[0] == 0)
		return (NULL);
	if (str2[0] == 0)
		return ((char *)str1);
	return (NULL);
}

char			*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	int		y;
	size_t	cp;

	i = 0;
	y = 0;
	if (str1[0] == 0 || str2[0] == 0)
		return (ft_check(str1, str2));
	while (str1[i] && i < len)
	{
		if (str1[i] == str2[0])
		{
			cp = i;
			while (str2[y] == str1[cp] && str2[y] && cp < len)
			{
				if (str2[y + 1] == 0)
					return ((char *)&str1[i]);
				++cp;
				++y;
			}
			y = 0;
		}
		++i;
	}
	return (0);
}
