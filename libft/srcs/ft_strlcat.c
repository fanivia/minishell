/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:42:19 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:33:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sumsize)
{
	unsigned int	dst1;
	unsigned int	src1;
	int				sum;

	dst1 = 0;
	src1 = 0;
	while (dst[dst1] != '\0')
		dst1++;
	while (src[src1] != '\0')
		src1++;
	if (sumsize <= dst1)
		sum = src1 + sumsize;
	else
		sum = src1 + dst1;
	src1 = 0;
	while ((src[src1] != '\0') && (dst1 + 1 < sumsize))
	{
		dst[dst1] = src[src1];
		dst1++;
		src1++;
	}
	dst[dst1] = '\0';
	return (sum);
}
