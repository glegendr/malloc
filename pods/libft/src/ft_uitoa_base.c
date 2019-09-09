/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:59:16 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/29 21:40:53 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_conv_low(char const *base_char, unsigned long long nb,
		unsigned int base)
{
	char				*s;
	int					i;
	unsigned long long	n;

	i = 0;
	n = nb;
	while (n >= base)
	{
		n /= base;
		++i;
	}
	++i;
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	s[0] = s[i];
	s[i--] = 0;
	while (nb >= base)
	{
		s[i--] = base_char[nb % base];
		nb /= base;
	}
	s[i] = base_char[nb];
	return (s);
}

static char		*ft_conv_up(char const *base_char, unsigned long long nb,
		unsigned int base)
{
	char				*s;
	int					i;
	unsigned long long	n;

	i = 0;
	n = nb;
	while (n >= base)
	{
		n /= base;
		++i;
	}
	++i;
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	s[0] = s[i];
	s[i--] = 0;
	while (nb >= base)
	{
		s[i--] = base_char[nb % base];
		nb /= base;
	}
	s[i] = base_char[nb];
	return (s);
}

static char		*ft_convertion_base(char flag, unsigned long long nb,
		unsigned int base)
{
	const char base_char_up[] = "0123456789ABCDEF";
	const char base_char_low[] = "0123456789abcdef";

	if (nb == 0)
		return (ft_strdup("0"));
	if (flag == 'x')
		return (ft_conv_low(base_char_low, nb, base));
	else
		return (ft_conv_up(base_char_up, nb, base));
}

static char		*ft_convertion(int i, unsigned long long nb,
		unsigned int base)
{
	char	*s;

	if (nb == 0)
		return (s = ft_strdup("0"));
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	s[i--] = 0;
	while (nb >= base)
	{
		s[i] = (nb % base) + 48;
		nb /= base;
		--i;
	}
	if (nb > 0 && nb < 10)
		s[i] = nb + 48;
	return (s);
}

char			*ft_uitoa_base(unsigned long long nb,
		unsigned int base, char flag)
{
	int					i;
	unsigned long long	n;

	i = 0;
	n = nb;
	while (n >= base)
	{
		n /= base;
		++i;
	}
	if (n < base)
		++i;
	if (base > 10)
		return (ft_convertion_base(flag, nb, base));
	return (ft_convertion(i, nb, base));
}
