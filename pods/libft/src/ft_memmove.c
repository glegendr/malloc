/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:44:43 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:49:14 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

static void		*ft_inf(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

static void		*ft_sup(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char *)src)[i];
		++i;
	}
	return (dest);
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_sup(dest, src, n));
	else
		return (ft_inf(dest, src, n));
	return (0);
}
