/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:10:14 by glegendr          #+#    #+#             */
/*   Updated: 2019/09/25 17:33:30 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

static void		*launch_realloc(void *ptr, size_t size, bool reaf)
{
	t_mem	*mem;
	void	*ret;

	if (!ptr)
		return (malloc(size));
	if (!(mem = find_ptr(ptr)))
		return (NULL);
	if (size <= mem->potential_size)
	{
		mem->size = size;
		return (ptr);
	}
	if (!(ret = malloc(size)))
	{
		if (reaf)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ret);
	ft_memcpy(ret, ptr, mem->size);
	free(ptr);
	return (ret);
}

void			*realloc(void *ptr, size_t n)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = launch_realloc(ptr, n, false);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

void			*reallocf(void *ptr, size_t n)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = launch_realloc(ptr, n, true);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

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
