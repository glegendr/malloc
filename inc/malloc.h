#ifndef MY_INC_H
# define MY_INC_H

#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#define SIZE_MALLOC (4090)

#define TINY_SIZE 256
#define TINY_PAGE_SIZE getpagesize() * 100
#define SMALL_SIZE 8192
#define SMALL_PAGE_SIZE SMALL_SIZE * 100
#define STATUS bool
#define USED true
#define FREED false

typedef enum		e_type
{
	TINY = 0,
	SMALL = 1,
	LARGE = 2,
}					t_type;

typedef struct		s_memory
{
	void			*ptr;
	size_t			size;
	STATUS			status;
	struct s_memory	*next;
}					t_mem;

typedef struct		s_head
{
	void			*ptr;
	size_t			size;
	size_t			size_left;
	t_mem			*mem;
	t_type			type;
	struct s_head	*next;
}					t_head;

t_head *g_malloc;


/*
** memory management functions
*/
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t nitems, size_t size);
void				free(void *ptr);

/*
** all other utils functions
*/
void				head_add(t_head **alst, t_head *new);
void				mem_add(t_head **alst, t_mem *new);
t_head				*find_place(size_t size, t_type type);
void				push_new_mmap(void *ptr, size_t size, t_type type);
void				*create_list(size_t size, t_head *head);
void				show_alloc_mem(void);
size_t				find_puissance(size_t);
t_mem				*find_ptr(void *ptr);
#endif
