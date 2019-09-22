#include <malloc.h>

size_t	find_my_type(size_t size)
{
	if (size > SMALL_SIZE)
		return (size);
	else if (size > TINY_SIZE)
		return (SMALL_SIZE);
	return (TINY_SIZE);
}

t_mem	*is_free_space(t_head *head, size_t size)
{
	t_mem *mem;

	mem = head->mem;
	while (mem)
	{
		if (mem->status == FREE && size <= mem->potential_size)
			return (mem);
		mem = mem->next;
	}
	return (NULL);
}

void	head_add(t_head **alst, t_head *new)
{
	new->next = *alst;
	*alst = new;
}

void	mem_add(t_head **alst, t_mem *new)
{
	if ((*alst)->mem == NULL)
	{
		(*alst)->mem = new;
		return ;
	}
	new->next = (*alst)->mem;
	(*alst)->mem = new;
}

void	push_new_mmap(void *ptr, size_t size, t_type type)
{
	t_head *head;

	head = mmap(NULL, getpagesize(), PROT_EXEC | PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	head->ptr = ptr;
	head->size = size;
	head->size_left = size;
	head->mem = NULL;
	head->type = type;
	head->next = NULL;
	head->len = 0;
	head_add(&g_malloc, head);
}

void	*create_list(size_t size, t_head *head)
{
	void		*ret;
	t_mem		*mem;

	if ((mem = is_free_space(head, size)))
	{
		mem->status = USED;
		mem->size = size;
		ret = mem->ptr;
		return (mem->ptr);
	}
	if ((int)((head->len + 1) * sizeof(t_mem) + sizeof(t_head)) < getpagesize())
		mem = (void *)head + (head->len * sizeof(t_mem) + sizeof(t_head));
	else
		mem = mmap(NULL, getpagesize(), PROT_EXEC | PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	ret = head->ptr + (head->size - head->size_left);
	mem->ptr = ret;
	mem->size = size;
	mem->potential_size = size + 16 - size % 16;
	mem->status = USED;
	mem->next = NULL;
	mem_add(&head, mem);
	head->size_left -= mem->potential_size;
	head->len += 1;
	return (ret);
}
