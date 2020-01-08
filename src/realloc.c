/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:10:14 by glegendr          #+#    #+#             */
/*   Updated: 2020/01/07 14:47:08 by glegendr         ###   ########.fr       */
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

char			*str_my_type(t_type type)
{
	if (type == LARGE)
		return ("LARGE");
	if (type == SMALL)
		return ("SMALL");
	return ("TINY");
}
