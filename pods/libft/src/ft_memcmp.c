/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:29:15 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:49:26 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		++i;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
