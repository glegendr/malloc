/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:12:30 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/20 17:41:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if ((s = (char *)malloc(sizeof(*s) * (size + 1))) == 0)
		return (0);
	while (i <= size)
	{
		s[i] = '\0';
		++i;
	}
	s[i] = '\0';
	return (s);
}
