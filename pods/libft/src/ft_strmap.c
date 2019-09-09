/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:30:20 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 14:48:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;
	int		y;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	if ((s2 = ft_strnew(i)) == NULL)
		return (NULL);
	y = 0;
	while (y < i)
	{
		s2[y] = (*f)(s[y]);
		++y;
	}
	s2[i] = '\0';
	return (s2);
}
