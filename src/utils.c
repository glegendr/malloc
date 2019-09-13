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
	head->splited_nb = 0;
	head->mem = NULL;
	head->type = type;
	head->next = NULL;
	head_add(&g_malloc, head);
}

void	*find_split(t_head *head, int *splited)
{
	t_mem *mem;

	mem = head->mem;
	if (!(head->splited_nb % 2))
	{
		*splited = 1;
		head->splited_nb += 1;
		return (head->ptr + (head->size - head->size_left));
	}
	while (mem)
	{
		if (mem->splited == 1 && !find_ptr(mem->ptr + (getpagesize() / 2)))
		{
			*splited = 2;
			head->splited_nb += 1;
			return (mem->ptr  + (getpagesize() / 2));
		}
		mem = mem->next;
	}
	return (NULL);
}

void	*create_list(size_t size, t_head *head)
{
	void		*ret;
	t_mem		*mem = mmap(NULL, find_puissance(sizeof(t_mem)), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	int		splited;

	splited = 0;
	if (size <= (size_t)(getpagesize() / 2))
		ret = find_split(head, &splited);
	else
		ret = head->ptr + (head->size - head->size_left);
	if (!ret)
		return (NULL);
	mem->ptr = ret;
	mem->size = size;
	mem->status = USED;
	mem->next = NULL;
	mem->splited = splited;
	mem_add(&head, mem);
	if (!splited || splited == 1)
		head->size_left -= find_puissance(size);

	return (ret);
}
