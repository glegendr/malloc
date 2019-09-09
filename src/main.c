#include <stdio.h>
#include <libft.h>
#include <sys/mman.h>

#define SIZE_MALLOC 152

#define TINY_SIZE 256
#define TINY_PAGE_SIZE TINY_SIZE * 100
#define SMALL_SIZE 8192
#define SMALL_PAGE_SIZE SMALL_SIZE * 100

t_list *g_malloc;

enum				e_status
{
	MMAPED = 0,
	NO_MMAPED = 1,
	UNMAPED = 2,
};

typedef struct		s_memory
{
	void			*ptr;
	size_t			size;
	enum e_status	status;
}					t_mem;


void	ft_free(void *ptr)
{
	int ret;

	if (!ptr)
		return ;
	ret = munmap(ptr, SIZE_MALLOC);
	printf("%s\n", ret == -1 ? "FREE_FAILED" : "FREE_SUCCED");
}

void	find_place(void)
{

}

void	push_memory_page(void *page, size_t size, enum e_status status)
{
	t_list list;
	t_mem mem;

	mem.ptr = page;
	mem.size = size;
	mem.status = status;
	list.content = &mem;
	list.content_size = sizeof(t_mem *);
	list.next = NULL;
	ft_lstadd(&g_malloc, &list);
}

void	*ft_malloc(size_t size)
{
	char *ptr = NULL;

	if (size > SMALL_SIZE)
	{
		ptr = mmap(NULL, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		printf("%s\n", ptr == ((void *) -1) ? "MMAP_FAILED" : "MMAP_SUCCED");
		if (ptr == ((void *) -1))
			return (NULL);
		return (ptr);
	}
	else if (size > TINY_SIZE)
	{
		find_place();
	}
	else
	{
		find_place();
	}
	return ptr;
}

void	*ft_realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	return (ptr);

}

void	fill_ptr(void *ptr)
{
	if (SIZE_MALLOC > SMALL_PAGE_SIZE)
	{
		printf("PAGE TOO BIG TO FILL\n");
		return ;
	}
	for (size_t i = 0; i < (SIZE_MALLOC - 1); ++i)
		((char *)ptr)[i] = (i % 10) + 48;
	((char *)ptr)[SIZE_MALLOC - 1] = '\0';
	printf("%s\n", ptr);

}

int		main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	void *ptr;
/*	t_list new;
		new.content = "Salut les potes";
		new.content_size = sizeof(char *);
		new.next = NULL;
	t_list new2;
		new2.content = "Salut les copains";
		new2.content_size = sizeof(char *);
		new2.next = NULL;
	ft_lstadd(&g_malloc, &new);
	ft_lstadd(&g_malloc, &new2);
	printf("%s\n", ((t_list)g_malloc[0]).content);
	printf("%s\n", ((t_list)g_malloc[1]).content);*/
	if (!(ptr = ft_malloc(SIZE_MALLOC)))
		return (-1);
	fill_ptr(ptr);
	ft_free(ptr);

	printf("%s\n", ptr);
	return (0);
}
