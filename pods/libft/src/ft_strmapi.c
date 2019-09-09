/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:47:43 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 14:44:45 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		s2[y] = (*f)(y, s[y]);
		++y;
	}
	s2[i] = '\0';
	return (s2);
}
