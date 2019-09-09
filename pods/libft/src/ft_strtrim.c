/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:06:09 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 16:49:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	deb;
	size_t	fin;
	size_t	len;
	char	*s1;

	deb = 0;
	if (s == NULL)
		return (NULL);
	fin = ft_strlen(s) - 1;
	len = 0;
	while (s[deb] == ' ' || s[deb] == '\n' || s[deb] == '\t')
		++deb;
	while (s[fin] == ' ' || s[fin] == '\n' || s[fin] == '\t')
		--fin;
	if (fin == 0 && deb == 0)
		return (ft_strdup(s));
	if (deb == ft_strlen(s))
		return (ft_strdup("\0"));
	if ((s1 = ft_strnew(fin - deb + 1)) == 0)
		return (0);
	while (deb <= fin)
		s1[len++] = s[deb++];
	return (s1);
}
