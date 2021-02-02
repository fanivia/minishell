/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:43:42 by fanivia           #+#    #+#             */
/*   Updated: 2020/07/30 01:39:32 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			*ft_calloc(size_t num, size_t size)
{
	void	*res;
	char	*str;
	size_t	i;

	res = malloc(num * size);
	if (!res)
		return (0);
	i = 0;
	str = (char *)res;
	while (i < (num * size))
		str[i++] = '\0';
	return (res);
}

char				*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

static size_t		ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!src)
		return (0);
	len = ft_strlen(src) + 1;
	dest = (char *)ft_calloc(len, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
