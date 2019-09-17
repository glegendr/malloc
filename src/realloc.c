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

	write(1, "REALLOC\n", 7);
	if (!ptr)
		return (malloc(size));
	if (!(mem = find_ptr(ptr)))
	{
		write(1, "NULL1\n", 6);
		return (NULL);
	}
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
	{
		write(1, "NULL1\n", 6);
		return (NULL);
	}
	ft_memcpy(ret, ptr, mem->size);
	free(ptr);
	write(1, "END\n", 4);
	return (ret);
}

void	*bzero_opti(void *s, size_t n)
{
	size_t i = 0;
	size_t z = n / 8;

	while (i < z)
	{
		if (((uint64_t *)s)[i] == 0)
			((uint64_t *)s)[i] = 0;
		++i;
	}
	z = 0;
	n %= 8;
	while (z < n)
	{
		if (((uint8_t *)s)[i] == 0)
			((uint8_t *)s)[i] = 0;
		++i;
		++z;
	}
	return (s);
}

void	*calloc(size_t nitems, size_t size)
{
	void *ret;

	write(1, "CALLOC\n", 7);
	if (!(ret = malloc(nitems * size)))
	{
		write(1, "NULL1\n", 6);
		return (NULL);
	}
	bzero_opti(ret, nitems * size);
	write(1, "END\n", 4);
	return (ret);
}

size_t	malloc_usable_size(void *ptr)
{
	t_mem *mem;

	if (!(mem = find_ptr(ptr)))
		return (0);
	return (mem->size);
}
