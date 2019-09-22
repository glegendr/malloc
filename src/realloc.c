/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:10:14 by glegendr          #+#    #+#             */
/*   Updated: 2019/09/22 18:11:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

void	*realloc(void *ptr, size_t size)
{
	t_mem	*mem;
	void	*ret;

	if (!ptr)
	{
		ret = malloc(size);
		return (ret);
	}
	if (!(mem = find_ptr(ptr)))
		return (NULL);
	if (size <= mem->potential_size)
	{
		mem->size = size;
		return (ptr);
	}
	if (!(ret = malloc(size)))
		return (NULL);
	if (!ptr)
		return (ret);
	ft_memcpy(ret, ptr, mem->size);
	free(ptr);
	return (ret);
}

void	*bzero_opti(void *s, size_t n)
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

void	*calloc(size_t nitems, size_t size)
{
	void *ret;

	if (!nitems || !size)
		return (NULL);
	if (!(ret = malloc(nitems * size)))
		return (NULL);
	bzero_opti(ret, nitems * size);
	return (ret);
}

size_t	malloc_usable_size(void *ptr)
{
	t_mem *mem;

	if (!(mem = find_ptr(ptr)))
		return (0);
	return (mem->size);
}
