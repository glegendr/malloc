#ifndef MY_INC_H
# define MY_INC_H

#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

#define TINY_PAGE_SIZE		4096
#define TINY_SIZE			TINY_PAGE_SIZE / 100
#define SMALL_PAGE_SIZE		TINY_PAGE_SIZE * 25
#define SMALL_SIZE			SMALL_PAGE_SIZE / 100
#define STATUS				int
#define FREED				0
#define USED				1
#define FREE				2

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
	size_t			potential_size;
	STATUS			status;
	struct s_memory	*next;
}					t_mem;

typedef struct		s_head
{
	void			*ptr;
	size_t			size;
	size_t			size_left;
	size_t			len;
	t_mem			*mem;
	t_type			type;
	struct s_head	*next;
}					t_head;

t_head *g_malloc;


void				print(char *s);

/*
** memory management functions
*/
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t nitems, size_t size);
void				free(void *ptr);
size_t				malloc_usable_size(void *ptr);

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
t_mem				*is_free_space(t_head *head, size_t size);
size_t				find_my_type(size_t size);
#endif
