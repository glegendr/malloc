/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:40:29 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:49:32 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmem.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if ((mem = (void *)malloc(sizeof(*mem) * size)) == 0)
		return (0);
	while (i < size)
	{
		((char *)mem)[i] = 0;
		++i;
	}
	return (mem);
}
