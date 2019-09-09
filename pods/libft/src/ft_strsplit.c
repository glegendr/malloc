/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:13:44 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 18:06:22 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_etage(const char *s, int c)
{
	int i;
	int len;
	int up;

	up = 0;
	len = 0;
	i = 0;
	while (s[i] == c)
		++i;
	while (s[i])
	{
		if (s[i] != c && len == 0)
		{
			up = up + 1;
			len = 1;
		}
		else if (s[i] == c)
			len = 0;
		++i;
	}
	return (up);
}

static int		ft_strlenmaison(const char *s, int up, char c)
{
	int i;
	int cp;
	int len;

	i = 0;
	cp = 0;
	len = 0;
	while (s[i] == c)
		++i;
	while (cp < up && s[i])
	{
		if (s[i] == c && len == 0)
		{
			++cp;
			len = 1;
		}
		else if (s[i] != c)
			len = 0;
		++i;
	}
	while (s[i] == c)
		i++;
	return (i);
}

static char		*ft_cut(const char *s, int up, int c, char *tab)
{
	int i;
	int y;

	y = 0;
	i = ft_strlenmaison(s, up, c);
	while (s[i] != c && s[i])
	{
		tab[y] = s[i];
		++y;
		++i;
	}
	tab[y] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		up;
	int		len;
	char	**tab;
	int		y;

	if (s == NULL)
		return (NULL);
	i = 0;
	up = ft_etage(s, c);
	if ((tab = (char **)malloc(sizeof(*tab) * (up + 2))) == 0)
		return (0);
	while (i < up)
	{
		y = ft_strlenmaison(s, i, c);
		len = 0;
		while (s[y] != c && s[y++])
			++len;
		tab[i] = (char *)malloc(sizeof(char) * (len + 1));
		tab[i] = ft_cut(s, i, c, tab[i]);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
