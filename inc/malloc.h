/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:19:20 by glegendr          #+#    #+#             */
/*   Updated: 2020/01/07 14:50:06 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>

# define TINY_PAGE_SIZE		4096
# define TINY_SIZE			40
# define SMALL_PAGE_SIZE		102400
# define SMALL_SIZE			1024
# define STATUS				int
# define FREED				0
# define USED				1
# define FREE				2

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
static pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

/*
** memory management functions
*/
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*reallocf(void *ptr, size_t size);
void				*calloc(size_t nitems, size_t size);
void				free(void *ptr);
size_t				malloc_usable_size(void *ptr);

/*
** all other utils functions
*/
void				head_add(t_head **alst, t_head *new);
void				mem_add(t_head **alst, t_mem *new);
void				push_new_mmap(void *ptr, size_t size, t_type type);
void				*create_list(size_t size, t_head *head);
void				show_alloc_mem(void);
t_mem				*find_ptr(void *ptr);
t_mem				*is_free_space(t_head *head, size_t size);
size_t				find_my_type(size_t size);
char				*str_my_type(t_type type);
#endif
