#include <malloc.h>

bool	all_freed(t_head *head)
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

void	show_alloc_mem(void)
{
	t_head	*tmp;
	t_mem	*mem;
	int		i;
	int		y;
	int		z;
	uint64_t total_size;

	total_size = 0;
	if (!g_malloc) //FAUT DEL PRINTF
	{
		printf("No memory has been malloc\n");
		return ;
	}
	tmp = g_malloc;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
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
		printf("%s : %p\n", tmp->type == 2 ? "LARGE" : tmp->type == 1 ? "SMALL" : "TINY", tmp->ptr);
		mem = tmp->mem;
		y = 0;
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
				printf("%p - %p : %zu octets\n", mem->ptr, mem->ptr + mem->size, mem->size);
				total_size += mem->size;
			}
			mem = mem->next;
			--y;
		}
		--i;
	}
	printf("Total : %llu octets\n", total_size);
}
