/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:28:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/03 19:06:12 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libmem.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** del
*/
void				del_tab(char **tab);

/*
** All ato_convertion
*/
int					ft_atoi(const char *s);
long int			ft_atoli(const char *s);
long long int		ft_atolli(const char *s);

/*
** All is_something
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
void				ft_isnegative(int n);
int					ft_isprint(int c);
int					ft_isspace(int c);

/*
** All ito_convertion
*/
char				*ft_itoa(int nbr);
char				*ft_itoa_base(long long nb, int base, char flag);
char				*ft_uitoa_base(unsigned long long nb, unsigned int base,
		char flag);

/*
** All list
*/
void				ft_lstadd(t_list **alst, t_list *na);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** All put_something
*/
void				ft_putstarstr(char **tab);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

/*
** All str
*/
void				ft_stradd(char **s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

/*
** all to_something
*/
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** random
*/
int					ft_sqrt(int i);
char				**tab_join(char **tab, char *s);
int					ft_recursive_factorial(int nb);
int					ft_abs(int i);
void				ft_bzero(void *s, size_t n);
#endif
