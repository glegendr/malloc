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

void	free(void *ptr)
{
	int ret;
	t_mem	*mem;

	if (!ptr)
		return ;
	if (!(mem = find_ptr(ptr)))
		return ;
	mem->status = FREED;
	ret = munmap(ptr, find_puissance(mem->size));
	mem->ptr = NULL;
}
