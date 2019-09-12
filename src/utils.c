#include <malloc.h>

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
	t_head *head = mmap(NULL, find_puissance(sizeof(t_head)), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	head->ptr = ptr;
	head->size = size;
	head->size_left = size;
	head->mem = NULL;
	head->type = type;
	head->next = NULL;
	head_add(&g_malloc, head);
}

void	*create_list(size_t size, t_head *head)
{
	void		*ret;
	t_mem		*mem = mmap(NULL, find_puissance(sizeof(t_mem)), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	ret = head->ptr + (head->size - head->size_left);
	mem->ptr = ret;
	mem->size = size;
	mem->status = USED;
	mem->next = NULL;
	mem_add(&head, mem);
	head->size_left -= find_puissance(size);

	return (ret);
}
