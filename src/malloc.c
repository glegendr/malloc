/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:10:27 by glegendr          #+#    #+#             */
/*   Updated: 2020/01/07 14:44:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

t_mem				*is_free_space(t_head *head, size_t size)
{
	t_mem *mem;

	mem = head->mem;
	while (mem)
	{
		if (mem->status == FREE && size <= mem->potential_size)
			return (mem);
		mem = mem->next;
	}
	return (NULL);
}

static t_head		*find_place(size_t size, t_type type)
{
	t_head *head;

	if (!g_malloc)
		return (NULL);
	head = g_malloc;
	while (head)
	{
		if ((head->size_left > size + 16 - size % 16
			|| is_free_space(head, size)) && type == head->type)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void			*launch_mmap(size_t size, size_t page_size, t_type type)
{
	void	*ptr;

	ptr = NULL;
	if (type != LARGE && (ptr = find_place(size, type)))
		return (create_list(size, ptr));
	ptr = mmap(NULL, page_size, PROT_EXEC | PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ptr == ((void *)-1))
		return (NULL);
	push_new_mmap(ptr, page_size, type);
	create_list(size, g_malloc);
	return (ptr);
}

void				*malloc(size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	if (size > SMALL_SIZE)
		ret = (launch_mmap(size, size, LARGE));
	else if (size > TINY_SIZE)
		ret = (launch_mmap(size, SMALL_PAGE_SIZE, SMALL));
	else
		ret = (launch_mmap(size, TINY_PAGE_SIZE, TINY));
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

size_t				malloc_usable_size(void *ptr)
{
	t_mem *mem;

	pthread_mutex_lock(&g_mutex);
	if (!(mem = find_ptr(ptr)))
	{
		return (0);
		pthread_mutex_unlock(&g_mutex);
	}
	pthread_mutex_unlock(&g_mutex);
	return (mem->size);
}
