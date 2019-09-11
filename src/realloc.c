#include <malloc.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char *)src)[i];
		++i;
	}
	return (dst);
}

void	*realloc(void *ptr, size_t size)
{
	t_mem	*mem;
	void	*ret;

//	printf("YO\n");
	if (!(mem = find_ptr(ptr)))
		return (NULL);
//	printf("SIZE: OLD->%zu NEW->%zu\n", mem->size, size);
	if (size <= mem->size)
	{
		mem->size = size;
		return (ptr);
	}
	else if (size <= find_puissance(mem->size))
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
