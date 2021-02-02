/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 05:07:04 by fanivia           #+#    #+#             */
/*   Updated: 2020/12/26 05:07:07 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/*
** fill a byte string with a byte value
*/
void				*ft_memset(void *b, int c, size_t len);

/*
** write zeroes to a byte string
*/
void				ft_bzero(void *s, size_t n);

/*
** copies n bytes from memory area src to memoty dst. If dst and src overlap,
** behavior is undefined.
*/
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
** copy string until character found
** copies bytes from string src to string dst. If the character c (as converted
** to an unsigned char) occurs in the string src, the copy stops and a pointer
** to the byte after the copy of c in the string dst is returned. Otherwise,
** n bytes are copied, and a NULL pointer is returned. The source
** and destination strings should not overlap, as the behavior is undefined.
*/
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** copies len bytes from string src to string dst. The two strings may overlap;
** The two strings may overlap; the copy is always done in non-destructive
** manner
*/
void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);

size_t				ft_strlcpy(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strnstr(const char *haystack, const char *needle,
																	size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

/*
** bonus part
*/

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
														void (*del)(void *));

#endif
