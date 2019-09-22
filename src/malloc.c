#include <malloc.h>
#include <libft.h>

t_head		*find_place(size_t size, t_type type)
{
	t_head *head;

	if (!g_malloc)
		return (NULL);
	head = g_malloc;
	while (head)
	{
		if ((head->size_left > size + 16 - size % 16
			|| is_free_space(head, size)) && type == head->type)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void		*launch_mmap(size_t size, size_t page_size, t_type type)
{
	void	*ptr;

	ptr = NULL;
	if (type != LARGE && (ptr = find_place(size, type)))
		return (create_list(size, ptr));
	ptr = mmap(NULL, page_size, PROT_EXEC | PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ptr == ((void *)-1))
		return (NULL);
	push_new_mmap(ptr, page_size, type);
	create_list(size, g_malloc);
	return (ptr);
}

void		*malloc(size_t size)
{
	void *ret;

	if (size > SMALL_SIZE)
		ret = (launch_mmap(size, size, LARGE));
	else if (size > TINY_SIZE)
		ret = (launch_mmap(size, SMALL_PAGE_SIZE, SMALL));
	else
		ret = (launch_mmap(size, TINY_PAGE_SIZE, TINY));
	return (ret);
}
