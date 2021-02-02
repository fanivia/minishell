/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:25:42 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/26 11:34:27 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_to_destination;
	unsigned char	*ptr_to_source;

	if (dst == src || len == 0)
		return (dst);
	ptr_to_destination = (unsigned char *)dst;
	ptr_to_source = (unsigned char *)src;
	if (ptr_to_destination > ptr_to_source)
	{
		while (len && ptr_to_source[len - 1])
		{
			ptr_to_destination[len - 1] = ptr_to_source[len - 1];
			len--;
		}
	}
	ft_memcpy(ptr_to_destination, ptr_to_source, len);
	return (ptr_to_destination);
}
