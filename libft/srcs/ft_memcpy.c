/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 02:01:17 by student           #+#    #+#             */
/*   Updated: 2020/06/04 22:46:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src1;
	unsigned int	i;
	unsigned char	*dst1;

	if (!src && !dst)
		return (NULL);
	i = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (i != n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
