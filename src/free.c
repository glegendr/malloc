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

	write(1, "FREE\n", 5);
	if (!ptr)
	{
		write(1, "NULL1\n", 6);
		return ;
	}
	if (!(mem = find_ptr(ptr)))
	{
		write(1, "NULL2\n", 6);
		return ;
	}
	mem->status = FREED; // try to mmunmap the head and all mem if (left_size < type && all_mem->status == FREED)
	ret = munmap(ptr, mem->size);
//	printf("%s\n", ret == -1 ? "FREE_FAIL" : "FREE_SUCCESS");
	mem->ptr = NULL;
		write(1, "END\n", 4);
}
