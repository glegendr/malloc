#include <malloc.h>

t_head		*find_place(size_t size, t_type type)
{
	t_head *head;

	if (!g_malloc)
		return (NULL);
	head = g_malloc;
	printf("%p\n", head);
	printf("%zu -- %zu -- %i -- %i\n", head->size_left, size, type,  head->type);
	while (head)
	{
		if (head->size_left >= size && type == head->type)
			return (head);
		printf("%zu -- %zu\n", head->size_left, size);
		head = head->next;
	}
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ptr = NULL;
	size_t	mem_size;

	if (size > SMALL_SIZE) {
		ptr = mmap(NULL, find_puissance(size), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		printf("%s\n", ptr == ((void *) -1) ? "LARGE_MMAP_FAILED" : "LARGE_MMAP_SUCCED");
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, size, LARGE);
		create_list(size, g_malloc);
		return (ptr);
	} else if (size > TINY_SIZE) {
		if ((ptr = find_place(size, SMALL)))
		{
			printf("PLACE_FOUND IN %p SIZE %zu -> SIZE LEFT AFTER %zu -- SMALL\n", ptr, size, ((t_head *)ptr)->size_left - size);
			return (create_list(size, ptr));
		}
		else {
			printf("NO PLACE_FOUND\n");
		ptr = mmap(NULL, SMALL_PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		printf("%s\n", ptr == ((void *) -1) ? "SMALL_MMAP_FAILED" : "SMALL_MMAP_SUCCED");
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, SMALL_PAGE_SIZE, SMALL);
		printf("-> %p -- %zu\n", g_malloc, g_malloc->size);
		create_list(size, g_malloc);
		return (ptr);
		}
	} else {
		if ((ptr = find_place(size, TINY)))
		{
			printf("PLACE_FOUND IN %p SIZE %zu -> SIZE LEFT AFTER %zu -- TINY\n", ptr, size, ((t_head *)ptr)->size_left - size);
			return (create_list(size, ptr));
		}
		else {
			printf("NO PLACE_FOUND\n");
		ptr = mmap(NULL, TINY_PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		printf("%s\n", ptr == ((void *) -1) ? "TINY_MMAP_FAILED" : "TINY_MMAP_SUCCED");
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, TINY_PAGE_SIZE, TINY);
		printf("-> %p -- %zu\n", g_malloc, g_malloc->size);
		create_list(size, g_malloc);
		return (ptr);
		}
	}
	return (ptr);
}
