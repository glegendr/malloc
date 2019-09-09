/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:07:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:49:28 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 1;
	while (cmp == 1 && i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			--cmp;
		++i;
	}
	--i;
	if (cmp == 1)
		return (0);
	return (&((char *)s)[i]);
}
