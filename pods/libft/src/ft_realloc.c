/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:37:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:49:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void		*ft_realloc(void *mem, int mem_size, int new_size)
{
	void *tmp;

	if ((tmp = malloc(new_size)) == NULL)
		return (NULL);
	if (mem == NULL)
		return (tmp);
	ft_memcpy(tmp, mem, mem_size);
	free(mem);
	return (tmp);
}
