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

	ret = 1;
	while (ret < size)
		ret <<= 1;
	if (ret < getpagesize())
		return getpagesize();
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
	printf("%s\n", ret == -1 ? "FREE_FAILED" : "FREE_SUCCED");
}
