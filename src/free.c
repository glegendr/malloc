/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:10:07 by glegendr          #+#    #+#             */
/*   Updated: 2019/09/23 17:10:46 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_mem			*find_ptr(void *ptr)
{
	t_head	*tmp;
	t_mem	*mem;

	tmp = g_malloc;
	while (tmp)
	{
		mem = tmp->mem;
		while (mem)
		{
			if (ptr == mem->ptr)
				return (mem);
			mem = mem->next;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static t_head	*find_head(void *ptr)
{
	t_head	*tmp;
	t_mem	*mem;

	tmp = g_malloc;
	while (tmp)
	{
		mem = tmp->mem;
		while (mem)
		{
			if (ptr == mem->ptr)
				return (tmp);
			mem = mem->next;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void		del_head(void *ptr)
{
	t_head *head1;
	t_head *head2;
	t_head *ptrhead;

	ptrhead = find_head(ptr);
	head1 = g_malloc;
	head2 = NULL;
	while (head1)
	{
		if (head1 == ptrhead)
		{
			if (head2)
				head2->next = head1->next;
			else
				g_malloc = head1->next;
			return ;
		}
		head2 = head1;
		head1 = head1->next;
	}
}

static bool		can_i_free(void *ptr)
{
	t_head	*head;
	t_mem	*mem;

	head = find_head(ptr);
	mem = head->mem;
	while (mem)
	{
		if (mem->status == USED && mem->ptr != ptr)
			return (false);
		mem = mem->next;
	}
	return (true);
}

void			free(void *ptr)
{
	int		ret;
	t_mem	*mem;

	pthread_mutex_lock(&g_mutex);
	if (!ptr)
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (!(mem = find_ptr(ptr)))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if ((find_head(ptr))->type != LARGE && !can_i_free(ptr))
	{
		pthread_mutex_unlock(&g_mutex);
		mem->status = FREE;
		return ;
	}
	mem->status = FREED;
	del_head(ptr);
	ret = munmap(ptr, mem->size);
	ptr = (void *)-1;
	pthread_mutex_unlock(&g_mutex);
}
