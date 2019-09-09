/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:44:46 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/25 21:59:58 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stradd(char **s, char c)
{
	size_t size;

	if (*s != NULL)
	{
		size = ft_strlen(*s);
		*s = ft_realloc(*s, size, size + 1);
		(*s)[size] = c;
		(*s)[size + 1] = '\0';
	}
	else
	{
		*s = ft_strnew(1);
		(*s)[0] = c;
	}
}
