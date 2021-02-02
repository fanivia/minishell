/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:44 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/25 22:41:34 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin_indent(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

static int	ft_end_indent(char const *s1, char const *set)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1) - 1;
	while (i != 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

static char	*ft_ret_str(const char *s1, char *str, size_t begin_indent,
						size_t i)
{
	size_t	j;

	if (!(str = (char *)malloc(sizeof(char) * (i - begin_indent + 2))))
		return (NULL);
	j = 0;
	while (s1[begin_indent] && begin_indent <= i)
	{
		str[j] = s1[begin_indent];
		j++;
		begin_indent++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin_indent;
	char	*str;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!*s1)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	begin_indent = ft_begin_indent(s1, set);
	i = ft_end_indent(s1, set);
	if (begin_indent > i)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = 0;
	}
	else
	{
		str = 0;
		str = ft_ret_str(s1, str, begin_indent, i);
	}
	return (str);
}
