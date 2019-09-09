/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:34:59 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/29 21:37:23 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_conv_low(char const *base_char, long long nb,
		int neg, int base)
{
	char			*s;
	int				i;
	long long		n;

	i = 0;
	n = nb;
	while (n >= base)
	{
		n /= base;
		++i;
	}
	++i;
	if ((s = (char *)malloc(sizeof(char) * (i + 1 + neg))) == 0)
		return (0);
	if (neg == 1)
		s[++i] = '-';
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

static char		*ft_conv_up(char const *base_char, long long nb,
		int neg, int base)
{
	char			*s;
	int				i;
	long long		n;

	i = 0;
	n = nb;
	while (n >= base)
	{
		n /= base;
		++i;
	}
	++i;
	if ((s = (char *)malloc(sizeof(char) * (i + 1 + neg))) == 0)
		return (0);
	if (neg == 1)
		s[++i] = '-';
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

static char		*ft_convertion_base(char flag, long long nb, int neg, int base)
{
	const char base_char_up[] = "0123456789ABCDEF";
	const char base_char_low[] = "0123456789abcdef";

	if (neg == 1)
		nb = -nb;
	if (nb == 0)
		return (ft_strdup("0"));
	if (flag == 'x')
		return (ft_conv_low(base_char_low, nb, neg, base));
	else
		return (ft_conv_up(base_char_up, nb, neg, base));
}

static char		*ft_convertion(int i, long long nb, int neg, int base)
{
	char *s;

	if (nb == -2147483648 && base == 10)
		return (s = ft_strdup("-2147483648"));
	if (nb == 0)
		return (s = ft_strdup("0"));
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	if (neg == 1)
	{
		s[0] = '-';
		nb = -nb;
	}
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

char			*ft_itoa_base(long long nb, int base, char flag)
{
	int			i;
	long long	n;
	int			neg;

	neg = 0;
	i = 0;
	n = nb;
	if (nb < 0)
	{
		++i;
		n = -n;
		neg = 1;
	}
	while (n >= base)
	{
		n /= base;
		++i;
	}
	if (n < base)
		++i;
	if (base > 10)
		return (ft_convertion_base(flag, nb, neg, base));
	return (ft_convertion(i, nb, neg, base));
}
