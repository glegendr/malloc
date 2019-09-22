/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:16:42 by glegendr          #+#    #+#             */
/*   Updated: 2019/09/22 18:17:56 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ret(unsigned int nb, int i)
{
	while (i-- > 0)
		nb /= 16;
	return (nb);
}

void				ft_putpoint(void *ptr)
{
	unsigned int	nb;
	int				i;
	const char		base_char[16] = "0123456789ABCDEF";

	if (!ptr)
	{
		write(1, "0x0", 3);
		return ;
	}
	i = 0;
	nb = (unsigned int)ptr >> 8;
	while (nb >= 16)
	{
		nb /= 16;
		++i;
	}
	nb = ret((unsigned int)ptr >> 8, i--);
	write(1, "0x", 2);
	while (nb < (unsigned int)ptr >> 8)
	{
		write(1, base_char + nb % 16, 1);
		nb = ret((unsigned int)ptr >> 8, i--);
	}
	write(1, base_char + nb % 16, 1);
}
