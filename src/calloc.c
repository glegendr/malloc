/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:45:53 by glegendr          #+#    #+#             */
/*   Updated: 2020/01/07 14:50:19 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stdint.h>

void			*bzero_opti(void *s, size_t n)
{
	size_t i;
	size_t z;

	i = 0;
	z = n / 8;
	while (i < z)
	{
		if (((uint64_t *)s)[i] != 0)
			((uint64_t *)s)[i] = 0;
		++i;
	}
	z = 0;
	n %= 8;
	while (z < n)
	{
		if (((uint8_t *)s)[z + 8 * i] != 0)
			((uint8_t *)s)[z + 8 * i] = 0;
		++z;
	}
	return (s);
}

void			*calloc(size_t nitems, size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	if (!nitems || !size)
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	if (!(ret = malloc(nitems * size)))
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	bzero_opti(ret, nitems * size);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
