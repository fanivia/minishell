/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:35:05 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:38:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((i != len) && (haystack[i] != '\0') && (needle[i] != '0'))
	{
		while ((haystack[i] == needle[j]) && (i != len))
		{
			if ((haystack[i] != '\0') && (needle[j] != '\0'))
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + (i - j));
		}
		j = 0;
		if ((haystack[i] != needle[j]) && (haystack[i] != '\0'))
			i++;
	}
	return (NULL);
}
