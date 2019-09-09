/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:47:52 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 14:44:03 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s;
	int		y;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((s = ft_strnew(i)) == 0)
		return (0);
	i = 0;
	y = 0;
	while (s1[i])
		s[y++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		s[y] = s2[i];
		++i;
		++y;
	}
	s[y] = 0;
	return (s);
}
