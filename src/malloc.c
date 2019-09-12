#include <malloc.h>

t_head		*find_place(size_t size, t_type type)
{
	t_head *head;

	if (!g_malloc)
		return (NULL);
	head = g_malloc;
	while (head)
	{
		if (head->size_left >= size && type == head->type)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ptr = NULL;

	if (size > SMALL_SIZE) {
		ptr = mmap(NULL, find_puissance(size), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, size, LARGE);
		create_list(size, g_malloc);
		return (ptr);
	} else if (size > TINY_SIZE) {
		if ((ptr = find_place(size, SMALL)))
			return (create_list(size, ptr));
		else {
		ptr = mmap(NULL, SMALL_PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, SMALL_PAGE_SIZE, SMALL);
		create_list(size, g_malloc);
		return (ptr);
		}
	} else {
		if ((ptr = find_place(size, TINY)))
			return (create_list(size, ptr));
		else {
		ptr = mmap(NULL, TINY_PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		if (ptr == ((void *) -1))
			return (NULL);
		push_new_mmap(ptr, TINY_PAGE_SIZE, TINY);
		create_list(size, g_malloc);
		return (ptr);
		}
	}
	return (ptr);
}
