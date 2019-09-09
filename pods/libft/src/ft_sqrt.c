/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:31:22 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/23 12:40:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_calc(int nb, int i)
{
	if (i * i < nb)
		return (ft_calc(nb, i + 1));
	else if (i * i == nb)
		return (i);
	else
		return (0);
}

int				ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	return (ft_calc(nb, i));
}
