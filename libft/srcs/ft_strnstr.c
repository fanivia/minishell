/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:10:14 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/29 19:38:18 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && (len > (i + j)))
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
