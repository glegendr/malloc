#include <malloc.h>

t_mem	*find_ptr(void *ptr)
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

t_head	*find_head(void *ptr)
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

size_t	find_puissance(size_t size)
{
	size_t ret;

	if (size == (size_t)-1)
		return (size);
	ret = 1;
	while (ret <= size && ret != 0)
		ret <<= 1;
	if (ret == 0)
		return (size);
	if (ret < (size_t)getpagesize())
		return (getpagesize());
	return (ret);
}

#include <libft.h>

void	show_mem()
{
	t_head *head = g_malloc;
	t_mem *mem;
	int i;
	int y;
	int fr;
	int us;
	int fd;

	for (y = 0; head; ++y, head = head->next)
	{
		for (i = 0, fr = 0, us = 0, fd = 0, mem = head->mem; mem; ++i, mem = mem->next)
		{
			if (mem->status == FREE)
				++fr;
			else if (mem->status == USED)
				++us;
			else
				++fd;
		}
		//print("MEM nb: ");
		//ft_putnbr(y);
		//print(" in: ");
		//ft_putnbr(i);
		//print(" free space: ");
		//ft_putnbr(fr);
		//print(" used space: ");
		//ft_putnbr(us);
		//print(" freed: ");
		//ft_putnbr(fd);
		//print(" Type: ");
		//print(head->type == LARGE ? "LARGE" : head->type == SMALL ? "SMALL" : "TINY");
		//print("\n");
	}
}

void	del_head(void *ptr)
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

bool	can_i_free(void *ptr)
{
	t_head *head = find_head(ptr);
	t_mem *mem = head->mem;

	while (mem)
	{
		if (mem->status == USED && mem->ptr != ptr)
			return (false);
		mem = mem->next;
	}
	return (true);
}

void	free(void *ptr)
{
	int ret;
	t_mem	*mem;

//	print("free\n");
//	show_mem();
	if (!ptr)
	{
		//print("end null\n");
		return ;
	}
	if (!(mem = find_ptr(ptr)))
	{
		//print("end mem\n");
		return ;
	}
	if ((find_head(ptr))->type != LARGE && !can_i_free(ptr))
	{
		mem->status = FREE;
		//print("end\n");
		return ;
	}
	mem->status = FREED;
	del_head(ptr);
	ret = munmap(ptr, mem->size);
	ptr = (void *)-1;
	//print("end\n");
}
