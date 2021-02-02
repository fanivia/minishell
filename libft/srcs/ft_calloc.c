/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:42:24 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/07 00:42:40 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = NULL;
	if (!(ptr = (void *)malloc(size * count)))
		return (NULL);
	else
	{
		while (i < size * count)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return ((void *)ptr);
}
