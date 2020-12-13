/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:00:11 by student           #+#    #+#             */
/*   Updated: 2020/06/08 13:37:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_fill(char **array, const char *str, char c,
		unsigned int a)
{
	unsigned int	i;
	int				i_str;
	int				i_array;

	i = 0;
	i_str = 0;
	i_array = 0;
	while ((i < a) && (str[i_str] != '\0'))
	{
		while (str[i_str] == c)
		{
			i_str++;
			i_array = 0;
		}
		while ((str[i_str] != c) && (str[i_str] != '\0'))
		{
			array[i][i_array] = str[i_str];
			i_array++;
			i_str++;
		}
		array[i][i_array] = '\0';
		i++;
	}
	return (array);
}

static char		**ft_freedom(char const **arr)
{
	int	j;

	j = 0;
	while (arr[j])
		free((char *)arr[j++]);
	free((char **)arr);
	return (NULL);
}

static char		**ft_wordalloc(char **arr, const char *str, unsigned int c)
{
	unsigned int	i;

	i = 0;
	while (i < c)
	{
		arr[i] = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (arr[i] == NULL)
			return (ft_freedom((char const **)arr));
		i++;
	}
	return (0);
}

static int		ft_delimnum(const char *str, char c)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			while ((str[i] != c) && (str[i] != '\0'))
				i++;
			i2++;
		}
	}
	return (i2);
}

char			**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = ft_delimnum(s, c);
	array = (char**)malloc(sizeof(char*) * (i + 1));
	if (array == NULL)
		return (NULL);
	array[i] = NULL;
	ft_wordalloc(array, s, i);
	array = ft_fill(array, s, c, i);
	return (array);
}
