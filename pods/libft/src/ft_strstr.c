/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:51 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/20 17:42:04 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(const char *str1, const char *str2)
{
	if (str1[0] == 0 && str2[0] == 0)
		return ((char *)str1);
	if (str1[0] == 0)
		return (NULL);
	if (str2[0] == 0)
		return ((char *)str1);
	return (NULL);
}

char		*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int y;
	int cp;

	i = 0;
	y = 0;
	if (str1[i] == 0 || str2[i] == 0)
		return (ft_check(str1, str2));
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			cp = i;
			while (str2[y] == str1[cp] && str2[y])
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
	return (NULL);
}
