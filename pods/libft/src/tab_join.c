/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:50:47 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/03 18:52:25 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

char		**tab_join(char **tab, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	if (tab == NULL)
	{
		tab = (char **)malloc(sizeof(char *) * 2);
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	while (tab[i])
		++i;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		++i;
	}
	del_tab(tab);
	tmp[i] = ft_strdup(s);
	tmp[i + 1] = NULL;
	return (tmp);
}
