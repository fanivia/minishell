/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:02:55 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/09 16:03:17 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		*substr = '\0';
		return (substr);
	}
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		count = 0;
		while (s[start] != '\0' && len--)
		{
			substr[count] = s[start];
			count++;
			start++;
		}
		substr[count] = '\0';
	}
	return (substr);
}
