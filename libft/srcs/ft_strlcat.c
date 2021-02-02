/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:40:43 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/21 21:34:25 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	return_value;

	i = ft_strlen(dst);
	return_value = i + ft_strlen(src);
	j = 0;
	if (i >= dstsize)
		return (dstsize + return_value - i);
	while ((src[j] != '\0') && ((i + 1) < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (return_value);
}
