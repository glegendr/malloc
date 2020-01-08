/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:09:36 by glegendr          #+#    #+#             */
/*   Updated: 2020/01/07 14:46:59 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

static bool		all_freed(t_head *head)
{
	t_mem *mem;

	mem = head->mem;
	while (mem)
	{
		if (mem->status == USED)
			return (false);
		mem = mem->next;
	}
	return (true);
}

static void		print_mem(t_mem *mem)
{
	ft_putpoint(mem->ptr);
	ft_putstr(" - ");
	ft_putpoint(mem->ptr + mem->size);
	ft_putstr(" : ");
	ft_putnbr(mem->size);
	ft_putstr(" octets\n");
}

static int		loop2(t_mem *mem, t_head *tmp, int total_size, int y)
{
	int z;

	z = 0;
	while (mem)
	{
		mem = mem->next;
		++y;
	}
	while (y > 0)
	{
		z = 0;
		mem = tmp->mem;
		while (++z < y)
			mem = mem->next;
		if (mem->status == USED)
		{
			print_mem(mem);
			total_size += mem->size;
		}
		mem = mem->next;
		--y;
	}
	return (total_size);
}

static int		loop1(int i, int z, int total_size)
{
	t_head *tmp;

	while (i > 0)
	{
		z = 0;
		tmp = g_malloc;
		while (++z < i)
			tmp = tmp->next;
		if (all_freed(tmp))
		{
			--i;
			continue ;
		}
		ft_putstr(str_my_type(tmp->type));
		ft_putstr(" : ");
		ft_putpoint(tmp->ptr);
		ft_putchar('\n');
		total_size += loop2(tmp->mem, tmp, 0, 0);
		--i;
	}
	return (total_size);
}

void			show_alloc_mem(void)
{
	t_head	*tmp;
	int		i;
	int		total_size;

	pthread_mutex_lock(&g_mutex);
	total_size = 0;
	if (!g_malloc)
	{
		pthread_mutex_unlock(&g_mutex);
		return (ft_putstr("No memory has been malloc\n"));
	}
	tmp = g_malloc;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	total_size = loop1(i, 0, 0);
	ft_putstr("Total : ");
	ft_putnbr(total_size);
	ft_putstr(" octets\n");
	pthread_mutex_unlock(&g_mutex);
}
