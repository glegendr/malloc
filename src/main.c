#include <malloc.h>

int		main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	void *ptr;
	t_head *tmp;
	int i = 0;

/*	printf("\nSTART OF MALLOC [1]\n");
	if (!(ptr = malloc(SIZE_MALLOC)))
		return (-1);
	printf("END OF MALLOC [1]\n");
	printf("%p left_size: %zu -- %zu\n", g_malloc->next, g_malloc->size_left,  (g_malloc->size_left + SIZE_MALLOC) - SMALL_PAGE_SIZE);
	printf("\nSTART OF MALLOC [2]\n");
	free(ptr);
	if (!(ptr = malloc(SIZE_MALLOC + 909)))
		return (-1);
	printf("END OF MALLOC [2]\n");

	printf("%p %zu  -----  %p %zu\n", (g_malloc->mem), (g_malloc->mem)->size,((g_malloc->mem)->next), ((g_malloc->mem)->next)->size);
	printf("\nSTART OF MALLOC [3]\n");
	free(ptr);
	if (!(ptr = malloc(SMALL_SIZE + 1)))
		return (-1);
	printf("END OF MALLOC [3]\n");
	printf("\nSTART OF MALLOC [4]\n");
	free(ptr);
	if (!(ptr = malloc(SMALL_SIZE)))
		return (-1);
	printf("END OF MALLOC [4]\n");
	printf("\nSTART OF MALLOC [5]\n");
	free(ptr);
	if (!(ptr = malloc(SIZE_MALLOC + 909)))
		return (-1);
	printf("END OF MALLOC [5]\n");
	printf("\nSTART OF MALLOC [6]\n");
	free(ptr);
	if (!(ptr = malloc(SIZE_MALLOC)))
		return (-1);
	printf("END OF MALLOC [6]\n");
	ptr = realloc(ptr, find_puissance(SIZE_MALLOC)*3);
	printf("END OF REALLOC\n");
//	printf("%p\n", ptr = malloc(0));
//	((char *)ptr)[0] = 'a';
//	printf("\n");
*/

	for (int y = 0; y < 900; ++y)
	{
		printf("\nSTART OF MALLOC [%i] SIZED %i\n", y, SMALL_SIZE - (9 * y));
		if (!(ptr = malloc(SMALL_SIZE - (9 * y))))
			return (-1);
		printf("END OF MALLOC [%i]\n", y);
		if (SMALL_SIZE - (9 * y) >= TINY_SIZE)
			free(ptr);
		if (y == 199)
		{
			printf("\nSTART OF MALLOC [BONUS %i]\n", y);
			if (!(ptr = malloc(0)))
				return (-1);
			printf("END OF MALLOC [BONUS %i]\n", y);
			break ;
		}
	}
	ptr = realloc(ptr, 4097);
	tmp = g_malloc;
	while (tmp)
	{
		t_mem *mem = tmp->mem;
		int y;
		for (y = 0; mem; ++y, mem = mem->next);
		printf("SIZE IN MALLOC %2i -- %4i -- %6zu TYPE: %s\n", i, y, tmp->size_left, tmp->type == 2 ? "LARGE" : tmp->type == 1 ? "SMALL" : "TINY");
		tmp = tmp->next;
		++i;
	}
	printf("MALLOC NBRS = %i\n", i);
	show_alloc_mem();
	printf("%p\n", ptr);
	((char *)ptr)[0] = 'a';
	free(ptr);
//	((char *)ptr)[0] = 'a';
//	printf("%p\n", ptr);
	show_alloc_mem();
	return (0);
}
