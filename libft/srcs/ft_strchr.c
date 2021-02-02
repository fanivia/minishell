/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:36:01 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/04 18:36:02 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != ch)
	{
		s++;
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
	}
	return ((char *)s);
}
/*
** Return the pointer to s here conditioned by while loop.
** If the first parameter is equal to ch, we should return it.
*/
