/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:25:06 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 14:49:12 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*s;
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	if ((s = ft_strnew(len)) == 0)
		return (0);
	while (str[start] && i < len)
	{
		s[i] = str[start];
		++i;
		++start;
	}
	return (s);
}
