/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:13:21 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/14 11:13:26 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1]) || (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_freedom(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free((char*)array[i]);
		array[i] = NULL;
		i++;
	}
	free((char **)array);
	return (NULL);
}

static char	**ft_malloc_for_words(char const *s, char c, char **arr)
{
	int	i;
	int	len;
	int	w;

	w = 0;
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			while (s[i] != c && s[i])
			{
				w++;
				i++;
				if (s[i] == c || !s[i])
				{
					if (!(arr[len] = (char *)malloc(sizeof(char) * (w + 1))))
						return (ft_freedom((char **)arr));
					len++;
					w = 0;
				}
			}
		(s[i] != '\0') ? i++ : 0;
	}
	return ((char **)arr);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		len;
	int		k;

	if (!s)
		return (NULL);
	len = ft_count_word((char *)s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	array[len] = NULL;
	array = ft_malloc_for_words((char *)s, c, (char **)array);
	len = 0;
	k = 0;
	while (*s != '\0' && array[len] != NULL)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			array[len][k++] = *s++;
		array[len++][k] = '\0';
		k = 0;
	}
	return (array);
}
